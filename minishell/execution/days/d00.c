/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:41:21 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 02:22:02 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	dup_here(t_file *str)
{
	if (str && str->type == 'H')
	{
		dup2(str->here_doc, 0);
	}
}

void	handle_redir(t_exeuction *str, t_va *va)
{
	t_file	*file;

	file = str->file;
	while (file)
	{
		if (file->name)
		{
			if (file->type == 'H')
				dup_here(file);
			else if (file->type == 'I')
				handle_input(file);
			else if (file->type == 'A')
				handle_append(file);
			else if (file->type == 'O')
				handle_output(file);
		}
		file = file->next;
	}
	handle_other_input(str, va);
}

void	read_from_here_doc(t_file *file)
{
	while (file)
	{
		if (file->type == 'H')
			handle_here_doc(file);
		file = file->next;
	}
}

void	handle_other_input(t_exeuction *str, t_va *va)
{
	if (check_if(str->file, 'A') == 0 && check_if(str->file, 'O') == 0)
	{
		if (ft_lstsize(str) > 1)
		{
			if (ft_lstsize(str) == va->size)
				close(va->fd[va->k][0]);
			dup2(va->fd[va->k][1], 1);
			close(va->fd[va->k][1]);
		}
	}
	if (check_if(str->file, 'H') == 0 && check_if(str->file, 'I') == 0)
	{
		if (ft_lstsize(str) != va->size && va->size != 1)
		{
			close(va->fd[va->k - 1][1]);
			dup2(va->fd[va->k - 1][0], 0);
			close(va->fd[va->k - 1][0]);
		}
	}
}

void	init(t_va *va)
{
	int	i;
	int	x;

	i = 0;
	while (i < (va-> size - 1))
		va->fd[i++] = malloc(sizeof(int) * 2);
	i = 0;
	while (i < (va->size - 1))
	{
		x = pipe(va->fd[i++]);
		if (x == -1)
		{
			perror("pipe");
			g_data.exit_status = 1;
			va->k = -1;
			return ;
		}
	}
}
