/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:54:47 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 15:06:52 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	helper_function(const char *s, int *type)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
			i++;
	if (s[i] == '+' || s[i] == '-')
		exit(write(2, "Error\nInvalid character in RGB\n", 32));
	return (i);
}

void	ft_is_char_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			exit(write(2, "Error\nSome invalid character\n", 30));
	}
}

int	ft_atoi(char *s)
{
	int			i;
	long		x;
	int			type;
	int			l;

	type = 1;
	if (s == NULL)
		exit(write(2, "Error\n404\n", 25));
	i = helper_function(s, &type);
	ft_is_char_valid(s);
	x = 0;
	l = 0;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		x = x * 10 + (s[i] - 48);
		if (x > 255)
			exit(write(2, "Error\n The RGB is out of ranf of 0 - 255\n", 42));
		else if (x < 0)
			exit(write(2, "Error\n The RGB is 0 - 255\n", 27));
		i++;
		l = x;
	}
	return (x * type);
}
