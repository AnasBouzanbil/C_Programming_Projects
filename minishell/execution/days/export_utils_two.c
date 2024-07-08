/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:17:28 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:25:09 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	ft_help_help_already_is(char *str, t_execute *s)
{
	char	*ss;

	ss = the_name(str);
	if (my_strcmp(s->name, ss) == 0)
	{
		free(ss);
		free(s->value);
		s->value = the_value(str);
		return (0);
	}
	free(ss);
	return (1);
}

int	ft_help_already_is(char *str, t_execute *s)
{
	char	*no_e;

	if (ft_help_help_already_is(str, s) == 0)
		return (0);
	no_e = name_without_equal(str);
	if (my_strcmp(s->name, no_e) == 0)
	{
		free(no_e);
		free(s->name);
		free(s->value);
		s->value = the_value(str);
		s->name = the_name(str);
		return (0);
	}
	free(no_e);
	return (1);
}

int	already_is(char *str)
{
	t_execute	*s;
	char		*test;

	s = g_data.str;
	while (s)
	{
		if (ft_help_already_is(str, s) == 0)
			return (0);
		test = name_without_equal(s->name);
		if (my_strcmp(test, str) == 0)
		{
			free(test);
			return (0);
		}
		free(test);
		s = s->next;
	}
	return (1);
}

void	add_to_exp(char *str)
{
	char	*name;
	char	*value;

	if (update(str) == 0)
		return ;
	if (already_is(str) == 0)
		return ;
	name = the_name(str);
	value = the_value(str);
	my_lstadd_back(&g_data.str, my_lstnew(name, value));
}

int	update(char *str)
{
	t_execute	*s;
	char		*ptr;
	char		*temp;

	s = g_data.str;
	if (before_is_plus(str) != 0)
	{
		while (s)
		{
			ptr = the_name(str);
			if (my_strcmp(s->name, ptr) == 0)
			{
				free(ptr);
				temp = s->value;
				ptr = the_value(str);
				s->value = my_strjoin(s->value, ptr);
				free(temp);
				free(ptr);
				return (0);
			}
			free(ptr);
			s = s->next;
		}
	}
	return (1);
}
