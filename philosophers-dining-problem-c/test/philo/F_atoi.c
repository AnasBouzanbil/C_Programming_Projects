/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   F_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:23 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/02 14:08:50 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(char *av[])
{
	int	i;
	int	x;

	i = 1;
	while (av[i])
	{
		x = 0;
		if (av[i][x] == '+')
			x++;
		while (av[i][x])
		{
			if (av[i][x] > '9' && av[i][x] < '0')
				return (-1);
			x++;
		}
		i++;
	}
	return (0);
}

long	the_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	t;

	t = the_time();
	while ((the_time() - t) < time)
		usleep(100);
}

static int	helper_function(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
			i++;
	if (s[i] == '-')
		return (-1);
	return (i);
}

int	ft_atoi(const char *s)
{
	int			i;
	long		x;
	int			type;
	long		l;

	type = 1;
	i = helper_function(s);
	if (i < 0)
		return (-1);
	x = 0;
	l = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		x = x * 10 + (s[i] - 48);
		if ((x > 2147483647 && type == 1) || ((x > 2147483648 && type == -1)))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
		l = x;
	}
	return (x * type);
}
