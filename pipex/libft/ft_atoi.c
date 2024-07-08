/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:23 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 19:49:48 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
