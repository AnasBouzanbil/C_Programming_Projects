/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:21:41 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/02 20:05:11 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_init(pthread_mutex_t *forks, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nof)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	state_change(t_philo *str, char *state)
{
	pthread_mutex_lock(str->print);
	printf("%ld | philo %d %s\n", (the_time() - str->time), str->idn, state);
	if (state[3] != 'd')
		pthread_mutex_unlock(str->print);
}

void	do_help(t_philo *str)
{
	pthread_mutex_lock(&str->forks[str->id]);
	state_change(str, "has taken a fork");
	pthread_mutex_lock(&str->forks[str->id_left]);
	state_change(str, "has taken another fork");
	pthread_mutex_lock(str->save);
	str->last_meal = the_time();
	pthread_mutex_unlock(str->save);
}

void	*function(void *ptr)
{
	t_philo			*str;

	str = ptr;
	while (1)
	{
		do_help(str);
		state_change(str, "is eating");
		ft_usleep(str->tte);
		pthread_mutex_lock(str->tcheck);
		if (str->check == 1)
			str->all++;
		pthread_mutex_unlock(str->tcheck);
		pthread_mutex_unlock(&str->forks[str->id]);
		pthread_mutex_unlock(&str->forks[str->id_left]);
		state_change(str, "is sleeping");
		ft_usleep(str->tts);
		state_change(str, "is thinking");
	}	
}
