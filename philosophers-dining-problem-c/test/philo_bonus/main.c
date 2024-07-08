/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:30:38 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/04 00:51:32 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	process(t_philo *philo)
{
	philo->last_meal = the_time();
	pthread_create(&philo->pid, NULL, function, philo);
	while (1)
	{
		if ((the_time() - philo->last_meal) > philo->ttd)
		{
			state_change(philo, "is died");
			exit(1);
		}
		if (philo->number_of_meals != -1)
		{
			if (philo->count == philo->number_of_meals)
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
		philo[x].time = ti;
		arr[x] = fork();
		if (!arr[x])
			process(&philo[x]);
		usleep(10);
		x++;
	}
}

void	ft_kill(int *arr, t_philo *philo)
{
	int	x;

	x = 0;
	while ((x < philo->nof))
	{
		kill(arr[x], SIGKILL);
		x++;
	}
}

void	waiting(int *arr, t_philo *philo)
{
	int	status;
	int	x;

	x = 0;
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			ft_kill(arr, philo);
			x++;
		}
		else
			x++;
		if (x == philo->nof)
			exit(0);
	}
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	sem_t	*sem;
	int		*arr;

	if (ac != 5 && ac != 6)
		return (0);
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_atoi(av[1]) <= 0))
		return (0);
	sem_unlink("sem");
	sem = sem_open("sem", O_CREAT, 0777, ft_atoi(av[1]));
	arr = malloc(sizeof(int) * ft_atoi(av[1]));
	if (init(av, &philo, sem) == -1)
		return (0);
	create_philo(philo, arr);
	waiting(arr, philo);
}
