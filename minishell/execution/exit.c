/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:13:20 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 00:54:10 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_check_first_number(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	handle_many_arguments(char *str)
{
	int	i;

	i = ft_check_first_number(str);
	if (i == -1)
	{
		ft_put_error("exit\nmini: exit: ", str, ": numeric argument requiredn\n");
		exit(255);
	}
	else
	{
		ft_putstr_fd("exit\nmini: exit: too many arguments\n", 2);
		g_data.exit_status = 1;
	}
}

void	handle_one_arguments(char *str)
{
	int	i;
	int	x;

	i = ft_check_first_number(str);
	x = ft_atoi(str);
	if (i == -1 || x == -1)
	{
		ft_put_error("exit\nmini: exit: ", str, ": numeric argument required\n");
		exit(255);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		exit(x);
	}	
}

void	help_exit(char **str)
{
	t_va	va;

	va.i = 0;
	if (ft_count(str) > 2)
		handle_many_arguments(str[1]);
	else
		handle_one_arguments(str[1]);
}

void	ft_exit(char **str)
{
	if (ft_count(str) != 1)
		help_exit(str);
	else
		(ft_putstr_fd("exit\n", 1), exit(g_data.exit_status));
}
