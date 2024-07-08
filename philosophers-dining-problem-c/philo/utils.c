/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:21:41 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/07 17:20:05 by abouzanb         ###   ########.fr       */
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
	pthread_mutex_lock(str->print); // to lock the mutex of printing the state of the philo
	printf("%ld | philo %d %s\n", (the_time() - str->time), str->idn, state); // to print the state of the philo
	if (state[0] != 'd') // if the philo is not dead
		pthread_mutex_unlock(str->print); // to unlock the mutex of printing the state of the philo 
	// if the philo is dead, the mutex will be unlocked in the function supervisore
}

void	do_help(t_philo *str) // to take the forks
{
	pthread_mutex_lock(&str->forks[str->id]);  // to lock the mutex of the fork
	state_change(str, "has taken a fork"); // to print the state of the philo
	pthread_mutex_lock(&str->forks[str->id_left]); // to lock the mutex of the another fork
	state_change(str, "has taken a fork"); // to print the state of the philo
	pthread_mutex_lock(str->save); // to lock for the mutex of updating the last_meal
	str->last_meal = the_time(); // to update the last_meal
	pthread_mutex_unlock(str->save); // to unlock the mutex of updating the last_meal
}

void	*function(void *ptr) // the function that the philo will execute
{
	t_philo			*str;

	str = ptr; // to get the structure of the philo
	while (1)
	{
		do_help(str); // check the function do_help
		state_change(str, "is eating");
		ft_usleep(str->tte); // to sleep for the time to eat 
		pthread_mutex_lock(str->tcheck);
		if (str->check == 1) // if the user has entered the number of time the philo has to eat
			++str->all; // increment the number of time that the philo has eaten
		pthread_mutex_unlock(str->tcheck); 
		pthread_mutex_unlock(&str->forks[str->id]); // to unlock the mutex of the fork
		pthread_mutex_unlock(&str->forks[str->id_left]); // to unlock the mutex of the another fork because the philo has finished eating
		state_change(str, "is sleeping"); // to print the state of the philo
		ft_usleep(str->tts); // to sleep for the time to sleep
		state_change(str, "is thinking"); // to print the state of the philo
	}	
}
