/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:05:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/07 17:45:42 by abouzanb         ###   ########.fr       */
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
		philo[i].last_meal = the_time(); // to get the time when the philo has started to eat which is the time of his creation
		pthread_create(&philo[i].pid, NULL, function, &philo[i]); // to create the thread of the philo
		usleep(100); 
		i++;
	}
}

int	f(t_philo *str, int *all)
{
	if (str->check == 1) // if the user has entered the number of time the philo has to eat 
	{
		if (str->all == str->number_of_eat) // if the philo has eaten the number of time the user has entered
		{
			(*all)++; // to increment the number of time that the philo has eaten in order to not check it again
			str->all++;  
		}
		if ((*all) == str->nof) // if all the philos have eaten the number of time the user has entered
			return (-1);
	}
	return (0);
}

void	supervisore(t_philo *str)
{
	int	i;
	int	all;

	all = 0;
	while (1) 																	// infinite loop until all the philos have eaten or one of them is dead
	{
		i = 0; 																				// to get back to the first philo
		while (i < str->nof) 																			 // loop to check if the philo is dead or not
		{
			pthread_mutex_lock(str[i].save); 																// to lock the mutex to check if the philo is dead or not
			if ((the_time() - str[i].last_meal) > str[i].ttd) 										// to check if the philo is dead or not
			{
				state_change(&str[i], "died"); // to print the state of the philo
				return ; // to exit the program
			}
			pthread_mutex_unlock(str[i].save); // to unlock the mutex
			pthread_mutex_lock(str[i].tcheck); // to lock the mutex to check if all the philos have eaten or not
			if (f(&str[i], &all) == -1)  // look at the function f to understand what it does
				return ;
			pthread_mutex_unlock(str[i].tcheck); // to unlock the mutex
			i++;
		}
		ft_usleep(1);
	}
}

int	main(int ac, char *av[]) 
{
	pthread_mutex_t	*fork; // mutex to take the forks and this table of mutex is shared between all the philos
	t_philo			*philo; // table of philos

	if (ac != 5 && ac != 6)  // to check if the number of arguments is valid or not
		return (0); 
	if (ac == 6 && (ft_atoi(av[5]) == 0 || ft_atoi(av[5]) == -1)) // to check if the number of time the philo has to eat is valid or not
		return (0);
	if (initi(av, &fork, &philo, ac) == -1) // to initialize the philos and the mutexes
		return (0);
	ft_pthread_create(philo); // to create the threads
	supervisore(philo); // to check if the philos are dead or not and if all the philos have eaten or not its like a supervisor
	return (0);
}

// this implementation is not the best one, but it works. 
// i will try to make it better in the future.
// it is not the best one because i have used a lot of mutexes and i have used a lot of variables to check if the philo is dead or not.

// the implementation is crazy, but it works.

// you can see that many thing that is usless, but i have used it to make the code more readable and more understandable.