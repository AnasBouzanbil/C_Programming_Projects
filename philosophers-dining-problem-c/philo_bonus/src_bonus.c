/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:40:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/07 17:55:51 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get(char *av[], t_philo *philo, int x, sem_t *sem)
{
	int		i;
	sem_t	*print;

	i = 0;
	sem_unlink("print");
	print = sem_open("print", O_CREAT, 0777, 1);
	while (i < x)
	{
		philo[i].id = i + 1;
		philo[i].nof = x;
		philo[i].ttd = ft_atoi(av[2]);
		philo[i].tts = ft_atoi(av[4]);
		philo[i].tte = ft_atoi(av[3]);
		philo[i].sem = sem;
		philo[i].count = 0;
		philo[i].print = print;
		philo[i].number_of_meals = ft_atoi(av[5]);
		if (philo[i].ttd <= 0 || philo[i].tts <= 0 || philo[i].tte <= 0)
			return (-1);
		i++;
	}
	return (0);
}

int	init(char *av[], t_philo **philo, sem_t *sem)
{
	int	i;

	if (parsing(av) == -1)
		return (-1);
	i = ft_atoi(av[1]);
	if (i <= -1)
		return (-1);
	(*philo) = malloc(sizeof(t_philo) * i);
	if (get(av, *philo, i, sem) == -1)
		return (-1);
	return (0);
}

void	state_change(t_philo *str, char *state)
{
	sem_wait(str->print);
	printf("%lu | philo %d %s\n", the_time() - str->time, str->id, state);
	if (state[0] != 'd')
		sem_post(str->print);
}

void	*function(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->sem);
		state_change(philo, "has taken a fork");
		sem_wait(philo->sem);
		state_change(philo, "has taken a fork");
		philo->last_meal = the_time();
		state_change(philo, "is eating");
		ft_usleep(philo->tts);
		philo->count++;
		sem_post(philo->sem);
		sem_post(philo->sem);
		state_change(philo, "is sleeping");
		ft_usleep(philo->tts);
		state_change(philo, "is thinking");
	}
}
