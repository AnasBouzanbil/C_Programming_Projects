/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:45:38 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:13:37 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	check_name(char *str)
{
	int	i;

	i = 0;
	if (str && (!str[0] || ft_isdigit(str[0]) == 1))
		return (1);
	while (str && str[i])
	{
		if (str[i] == '+' || str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_if_it_isfirst(char *str)
{
	t_execute	*ptr;
	char		*plr;

	plr = name_without_equal(g_data.str->name);
	if (my_strcmp(str, plr) == 0)
	{
		ptr = g_data.str;
		g_data.str = g_data.str->next;
		free(ptr->name);
		free(ptr->value);
		free(ptr);
		free(plr);
		return (1);
	}
	free(plr);
	return (0);
}

int	ft_help_check_if_there_and_unset_it(char *str, t_execute *temp)
{
	char		*comd;
	t_execute	*ptr;

	comd = name_without_equal(temp->next->name);
	if (my_strcmp(comd, str) == 0)
	{
		ptr = temp->next;
		temp->next = temp->next->next;
		free(ptr->name);
		free(comd);
		free(ptr->value);
		free(ptr);
		return (1);
	}
	free(comd);
	return (0);
}

void	check_if_there_and_unset_it(char *str)
{
	t_execute	*temp;

	temp = g_data.str;
	if (temp == NULL)
		return ;
	if (check_if_it_isfirst(str) == 1)
		return ;
	while (temp)
	{
		if (temp->next == NULL)
			return ;
		if (ft_help_check_if_there_and_unset_it(str, temp) == 1)
			return ;
		temp = temp->next;
	}
}

void	ft_unset(char **str)
{
	t_va	va;

	va.i = 1;
	va.k = 0;
	if (ft_count(str) == 1)
		return ;
	while (str[va.i])
	{
		if (check_name(str[va.i]) == 1)
		{
			ft_put_error("mini: unset: `", str[va.i], \
			"': not a valid identifier\n");
			va.i++;
			va.k++;
			g_data.exit_status = 1;
		}
		else
			check_if_there_and_unset_it(str[va.i++]);
	}
	if (va.k == 0)
		g_data.exit_status = 0;
}
