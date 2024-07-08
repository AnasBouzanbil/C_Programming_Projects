/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:05:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/01 16:52:40 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pthread_create(t_philo *philo)
{
	int		i;
	long	consttime;

	consttime = the_time();
	i = 0;
	while (i < philo->nof)
	{
		philo[i].time = consttime;
		pthread_mutex_lock(philo->save);
		philo[i].last_meal = the_time();
		pthread_mutex_unlock(philo->save);
		pthread_create(&philo[i].pid, NULL, function, &philo[i]);
		usleep(100);
		i++;
	}
}

int	f(t_philo *str, int *all)
{
	if (str->check == 1)
	{
		if (str->all == str->number_of_eat)
			(*all)++;
		if ((*all) == str->number_of_eat)
			return (-1);
	}
	return (0);
}

void	supervisore(t_philo *str)
{
	int	i;
	int	all;

	all = 0;
	while (1)
	{
		i = 0;
		while (i < str->nof)
		{
			pthread_mutex_lock(str[i].save);
			if ((the_time() - str[i].last_meal) > str[i].ttd)
			{
				state_change(&str[i], "is died");
				return ;
			}
			if (f(&str[i], &all) == -1)
				return ;
			pthread_mutex_unlock(str[i].save);
			pthread_mutex_lock(str[i].tcheck);
			pthread_mutex_unlock(str[i].tcheck);
			i++;
		}
		ft_usleep(1);
	}
}

int	main(int ac, char *av[])
{
	pthread_mutex_t	*fork;
	t_philo			*philo;

	if (ac != 5 && ac != 6)
		return (0);
	if (ac == 6 && (ft_atoi(av[5]) == 0 || ft_atoi(av[5]) == -1))
		return (1);
	if (initi(av, &fork, &philo, ac) == -1)
		return (0);
	ft_pthread_create(philo);
	supervisore(philo);
	return (0);
}
