/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d04.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:26:58 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/12 23:58:37 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	fill_env(char **env)
{
	int		i;
	char	*before;
	char	*after;

	i = 0;
	while (env[i])
	{
		before = the_name(env[i]);
		after = the_value(env[i]);
		my_lstadd_back(&g_data.str, my_lstnew(before, after));
		i++;
	}
}

int	ft_isalnum(int a)
{
	if ((a <= 90 && a >= 65) || (a <= 122 && a >= 97) || (a <= '9' && a >= '0'))
		return (1);
	return (0);
}
