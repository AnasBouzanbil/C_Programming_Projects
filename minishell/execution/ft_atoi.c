/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:28:32 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 01:10:47 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	helper_function(const char *s, int *type)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
			i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*type = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *s)
{
	int			i;
	long		x;
	int			type;
	int			l;

	type = 1;
	i = 0;
	i = helper_function(s, &type);
	x = 0;
	l = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		x = x * 10 + (s[i] - 48);
		if (l > x)
		{
			if (type < 0)
				return (0);
			else if (type > 0)
				return (-1);
		}
		i++;
		l = x;
	}
	return (x * type);
}

int	open_all(t_exeuction *str)
{
	t_file	*file;

	while (str)
	{
		file = str->file;
		while (file)
		{
			if (file->type == 'H')
				if (handle_here_doc(file) == 1)
					return (1);
			file = file->next;
		}
		str = str->next;
	}
	return (0);
}

void	wait_for_them(t_va *va)
{
	int	i;
	int	status;

	i = 0;
	while (i < va->size)
	{
		if (waitpid(-1, &status, 0) == va->id)
		{
			if (WIFEXITED(status))
				g_data.exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(va->i))
				g_data.exit_status = (WTERMSIG(status) + 128);
		}
		i++;
	}
}
