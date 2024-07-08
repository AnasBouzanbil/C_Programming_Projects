/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:30:38 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/04 22:36:14 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	process(t_philo *philo)
{
	philo->last_meal = the_time(); // to get the time when the philo has started to eat which is the time of his creation
	pthread_create(&philo->pid, NULL, function, philo); // to create the thread of the philo whihc will its routine function
	// this wile loop will be the supervisor of the philo
	while (1) // infinite loop to check if the philo is dead or not
	{
		if ((the_time() - philo->last_meal) > philo->ttd) // to check if the philo is dead or not
		{
			state_change(philo, "died"); 
			exit(1); // to exit the program  with status 1 which means that the philo is dead
		}
		if (philo->number_of_meals != -1) // if the user has entered the number of time the philo has to eat
		{
			if (philo->count == philo->number_of_meals) //
				exit(0);
		}
	}
}

void	create_philo(t_philo *philo, int *arr)
{
	int		x;
	long	ti;

	x = 0;
	ti = the_time();
	while (x < philo->nof)
	{
		philo[x].time = ti; // to get the time when the philo has started to eat which is the time of his creation
		arr[x] = fork(); // to create the philo
		if (!arr[x]) // if the philo is created 
			process(&philo[x]); // then execute the function process 
		usleep(10); 
		x++;
	}
}

void	ft_kill(int *arr, t_philo *philo)
{
	int	x;

	x = 0; 
	while ((x < philo->nof)) // loop to kill all the philos 
	{
		kill(arr[x], SIGKILL); // to kill the philo in that index
		x++; 
	}
}

void	waiting(int *arr, t_philo *philo)
{
	int	status;
	int	x;

	x = 0;
	while (1) // infinite loop until all the philos have eaten or one of them is dead 
	{
		waitpid(-1, &status, 0); // to wait for the philos 
		if (WEXITSTATUS(status) == 1) // if one of the philos is dead
		{ 
			ft_kill(arr, philo); // to kill all the philos 
			x++;
		}
		else // if one of the philos has eaten the number of time the user has entered
			x++;  
		if (x == philo->nof) // if all the philos have eaten the number of time the user has entered
			exit(0); // to exit the program
	}
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	sem_t	*sem;
	int		*arr;

	if (ac != 5 && ac != 6) // to check if the number of arguments is valid or not
		return (0);
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_atoi(av[1]) <= 0))
		return (0);
	sem_unlink("sem"); // to unlink the semaphore if it already exists
	sem = sem_open("sem", O_CREAT, 0777, ft_atoi(av[1])); // to create the semaphore and to initialize it with the number of philos that the user has entered
	arr = malloc(sizeof(int) * ft_atoi(av[1])); // to create an array of int to store the pid of the philos
	if (init(av, &philo, sem) == -1) // to get the arguments
		return (0); 
	create_philo(philo, arr); // to create the philos
	waiting(arr, philo); // to wait for the philos
}
