/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:20:21 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 00:51:05 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_child(t_exeuction *str, t_va *va)
{	
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	handle_redir(str, va);
	if (check_if_built(str) == 0)
	{
		if (str->str[0][0] == '\0')
		{
			ft_putstr_fd("mini:  : command not found\n", 2);
			exit(127);
		}
		get_path(str, va);
		if (va->comd == NULL)
			error_print(1, str->str[0]);
		va->env = get_env();
		my_close(va);
		execve(va->comd, str->str, va->env);
		perror("execve");
		exit(1);
	}
	free_node(str);
	exit(0);
}

void	creates_childs(t_exeuction *str, t_va *va)
{
	va->k = 0;
	va->i = 0;
	if (open_all(str) == 1)
		return ;
	while (str)
	{
		va->id = fork();
		if (va->id == -1)
		{
			ft_putstr_fd("mini-3.2$: fork: Resource temporarily \
unavailable\n", 2);
			g_data.exit_status = 0;
			return ;
		}
		if (va->id == 0)
			execute_child(str, va);
		ft_close(va, str);
		str = str->next;
		(va->k)++;
	}
}

void	ft_help_simple(t_exeuction *str, t_va *av)
{
	if (str->str[0][0] == '\0')
	{
		ft_putstr_fd("mini:  : command not found\n", 2);
		exit(127);
	}
	get_path(str, av);
	if (av->comd == NULL)
		error_print(1, str->str[0]);
	av->env = get_env();
	execve(av->comd, str->str, av->env);
	perror("execve: ");
	exit(1);
}

void	simple(t_exeuction *str, t_va *av)
{
	if (handle_redir_one_comand(str) == 1)
		return ;
	if (check_if_built(str) == 0)
	{
		av->id = fork();
		if (av->id == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			ft_help_simple(str, av);
		}
		waitpid(av->id, &av->i, 0);
		if (WIFEXITED(av->i))
			g_data.exit_status = WEXITSTATUS(av->i);
		else if (WIFSIGNALED(av->i))
			g_data.exit_status = (WTERMSIG(av->i) + 128);
	}
}

void	execution(t_exeuction *str)
{
	t_va	va;

	va.size = ft_lstsize(str);
	if (va.size == 0)
		return ;
	if (va.size == 1)
	{
		if (open_all(str) == 1)
			return ;
		simple(str, &va);
	}
	else
	{
		va.fd = malloc(sizeof(int *) * va.size - 1);
		init(&va);
		if (va.k == -1)
			return ;
		creates_childs(str, &va);
		wait_for_them(&va);
		my_close(&va);
		va.i = 0;
		while (va.i < (va.size - 1))
			free(va.fd[va.i++]);
		free(va.fd);
	}
}
