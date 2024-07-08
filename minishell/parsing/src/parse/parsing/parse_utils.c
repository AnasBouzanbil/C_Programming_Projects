/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:04:45 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/16 16:47:50 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// initializ the redirection 
t_file	*initialize_redirection(char *filename, char type, int a)
{
	t_file	*red;

	if (!filename)
		return (NULL);
	red = (t_file *)malloc(sizeof(t_file));
	if (!red)
		return (NULL);
	red->name = ft_strdup(filename);
	red->type = type;
	red->x = a;
	red->next = NULL;
	return (red);
}

//initializ the execution struct
t_exeuction	*initialize_execution(char **str, t_file *file)
{
	t_exeuction	*cmd;

	if (!str)
		return (NULL);
	cmd = (t_exeuction *)malloc(sizeof(t_exeuction));
	if (!cmd)
		return (NULL);
	cmd->str = str;
	cmd->file = file;
	cmd->next = NULL;
	return (cmd);
}

t_exeuction	*last_exec(t_exeuction *exec)
{
	if (!exec)
		return (NULL);
	while (exec->next != NULL)
		exec = exec->next;
	return (exec);
}

// remplie liste d'execution
void	add_back_execution(t_exeuction **list_exec, t_exeuction *exec)
{
	t_exeuction	*tmp;

	tmp = (*list_exec);
	if (!(*list_exec))
		(*list_exec) = exec;
	else
	{
		tmp = last_exec(*list_exec);
		tmp->next = exec;
	}
}

t_file	*last_file(t_file *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
