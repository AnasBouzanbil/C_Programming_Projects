/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:59:31 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:28:28 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	print_export(void)
{
	t_execute	*ptr;

	ptr = g_data.str;
	while (ptr)
	{
		printf("declare -x %s", ptr->name);
		if (ptr->value)
			printf("\"%s\"", ptr->value);
		printf("\n");
		ptr = ptr->next;
	}
}

void	add_to_export(char **cmd)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (cmd[i])
	{	
		if (is_valid(cmd[i]) == 0)
			a++;
		else
			add_to_exp(cmd[i]);
		i++;
	}
	if (a == 0)
		g_data.exit_status = 0;
}

int	is_no(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0' || str[0] != '-')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	before_is_plus(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
		{
			if (i != 0 && str[i - 1] == '+')
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

void	ft_export(char **cmd)
{
	if (ft_count(cmd) == 1)
	{
		print_export();
		g_data.exit_status = 0;
	}
	else
		add_to_export(cmd);
}
