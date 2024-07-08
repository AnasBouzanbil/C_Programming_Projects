/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:31:29 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 02:27:15 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_count(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_help_chnage_pld_pwd(char *cmd, int *i, int *x)
{
	t_execute	*g;

	g = g_data.str;
	while (g)
	{
		if (my_strcmp("OLDPWD=", g->name) == 0)
		{
			*i = 1;
			free(g->value);
			g->value = cmd;
		}
		if (my_strcmp("PWD=", g->name) == 0)
		{
			*x = 1;
			free(g->value);
			g->value = getcwd(NULL, 0);
		}
		g = g->next;
	}
}

void	chnage_old_pwd(char *cmd)
{
	int			i;
	int			x;

	i = 0;
	x = 0;
	ft_help_chnage_pld_pwd(cmd, &i, &x);
	if (i == 0)
		my_lstadd_back(&g_data.str, \
			my_lstnew(my_strdup("OLDPWD="), cmd));
	if (i == 0)
		my_lstadd_back(&g_data.str, \
			my_lstnew(my_strdup("PWD="), getcwd(NULL, 0)));
}
