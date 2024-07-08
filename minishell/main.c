/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:49:09 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 00:09:31 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/include/minishell.h"

void	handle_control_c(int sig)
{
	sig = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_data.exit_status = sig;
}

void	ft_help_main(char *str, t_exeuction *ptr, int *fd)
{
	execution(ptr);
	free_node(ptr);
	add_history(str);
	free(str);
	dup2(fd[0], 0);
	dup2(fd[1], 1);
}

int	main(int ac, char *av[], char *env[])
{
	t_exeuction	*ptr;
	char		*str;
	int			fd[2];

	ac = 0;
	av = env;
	fill_env(env);
	fd[0] = dup(0);
	fd[1] = dup(1);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, handle_control_c);
		str = readline("mini-3.2$ : ");
		signal(SIGINT, SIG_IGN);
		if (str == NULL)
		{
			ft_putstr_fd("exit", 1);
			return (g_data.exit_status);
		}
		ptr = filed_struct(str);
		ft_help_main(str, ptr, fd);
	}
}
