/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d03.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:37:01 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:07:46 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	help_check_if_built(t_exeuction *str)
{
	if (my_strcmp(str->str[0], "unset") == 0)
	{
		ft_unset(str->str);
		return (1);
	}
	else if (my_strcmp(str->str[0], "exit") == 0)
	{
		ft_exit(str->str);
		return (1);
	}
	else if (my_strcmp(str->str[0], "export") == 0)
	{
		ft_export(str->str);
		return (1);
	}
	else if (my_strcmp(str->str[0], "pwd") == 0 \
	|| my_strcmp(str->str[0], "PWD") == 0)
	{
		ft_pwd();
		return (1);
	}
	return (0);
}

int	check_if_built(t_exeuction *str)
{
	if (!str || !str->str || str->str[0] == NULL)
		return (1);
	if (my_strcmp(str->str[0], "echo") == 0 || strcmp(str->str[0], "ECHO") == 0)
	{
		ft_echo(str->str);
		return (1);
	}
	else if (my_strcmp(str->str[0], "cd") == 0)
	{
		ft_cd(str->str);
		return (1);
	}
	else if (my_strcmp(str->str[0], "env") == 0 \
	|| my_strcmp(str->str[0], "ENV") == 0)
	{
		ft_env();
		return (1);
	}
	if (help_check_if_built(str) == 1)
		return (1);
	return (0);
}

char	**get_env(void)
{
	t_execute	*temp;
	t_va		av;
	char		**env;

	av.i = 0;
	temp = g_data.str;
	av.size = my_lstsize(g_data.str);
	if (av.size == 0)
		return (NULL);
	env = ft_calloc((sizeof(char *) * (av.size + 1)), 1);
	if (env == NULL)
		return (NULL);
	while (temp)
	{
		env[av.i] = my_strjoin(temp->name, temp->value);
		temp = temp->next;
		av.i++;
	}
	env[av.i] = NULL;
	return (env);
}
