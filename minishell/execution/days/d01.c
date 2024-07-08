/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:45:01 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 01:06:07 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	ft_close(t_va *va, t_exeuction *str)
{
	int	i;

	i = 0;
	if (va->k != 0)
	{
		close(va->fd[va->k - 1][0]);
		close(va->fd[va->k - 1][1]);
	}
	if (ft_lstsize(str) == 1)
	{
		close(va->fd[va->k - 1][0]);
		close(va->fd[va->k - 1][1]);
	}
}

void	my_close(t_va *va)
{
	int	i;

	i = 0;
	while (i < va->size - 1)
	{
		close(va->fd[i][0]);
		close(va->fd[i][1]);
		i++;
	}
}

void	error_print(int i, char *cmd)
{
	if (i == 1)
	{
		ft_putstr_fd("mini: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

int	my_lstsize(t_execute *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

int	check_if(t_file *str, char type)
{
	while (str)
	{
		if (str->type == type)
			return (1);
		str = str->next;
	}
	return (0);
}
