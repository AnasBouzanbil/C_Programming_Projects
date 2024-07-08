/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:36:07 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/16 15:28:44 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_number_lenth(int a)
{
	int	x;

	x = 0;
	if (a == 0)
	{
		return (1);
	}
	if (a < 0)
	{
		a = a * -1;
		x++;
	}
	while (a > 0)
	{
		a = a / 10;
		x++;
	}
	return (x);
}

static void	helper_function(char *str, int a, int x)
{
	if (a < 0)
	{
		str[0] = '-';
		a = a * -1;
	}
	if (a == 0)
	{
		str[0] = '0';
	}
	while (a > 0)
	{
		str[x] = (a % 10) + '0';
		x--;
		a = a / 10;
	}
}

char	*ft_itoa(int a)
{
	int		x;
	char	*str;

	if (a == -2147483648)
		return (ft_strdup("-2147483648"));
	x = ft_number_lenth(a);
	str = (char *)malloc(sizeof(char) * (x + 1));
	if (str == NULL)
		return (NULL);
	str[x] = '\0';
	x--;
	helper_function(str, a, x);
	return (str);
}
