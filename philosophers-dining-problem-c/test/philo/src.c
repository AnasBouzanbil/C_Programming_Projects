/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:08:26 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/02 20:03:48 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initi(char *av[], pthread_mutex_t **forks, t_philo **philo, int ac)
{
	int	phi;
	int	i;

	i = 0;
	if (parsing(av) == -1)
		return (-1);
	phi = ft_atoi(av[1]);
	if (phi <= 0)
		return (-1);
	*philo = malloc(sizeof(t_philo) * phi);
	*forks = malloc(sizeof(pthread_mutex_t) * phi);
	(*philo)->nof = phi;
	get_init(*forks, *philo);
	if (get_that(av, *forks, *philo, ac) == -1)
		return (-1);
	return (0);
}

void	minihelp(char *av[], t_struct *ptr, t_philo *p, int i)
{
		p->idn = i + 1;
		p->id = i;
		p->ttd = ft_atoi(av[2]);
		p->save = ptr->save;
		p->print = ptr->print;
		p->tcheck = ptr->tcheck;
		p->tte = ft_atoi(av[3]);
		p->tts = ft_atoi(av[4]);
}

void	little(int ac, t_philo *p, char *av[], int i)
{
	if (ac == 6)
	{
		p->check = 1;
		p->number_of_eat = ft_atoi(av[5]);
	}
	else
		p->check = -1;
	if (i == (p->nof - 1))
		p->id_left = 0;
	else
		p->id_left = (i + 1);
}

int	get_that(char *av[], pthread_mutex_t *forks, t_philo *philo, int ac)
{
	int				i;
	t_struct		*ptr;
	int				x;

	ptr = malloc(sizeof(t_struct));
	ptr->save = malloc(sizeof(pthread_mutex_t));
	ptr->tcheck = malloc(sizeof(pthread_mutex_t));
	ptr->print = malloc(sizeof(pthread_mutex_t));
	i = 0;
	x = philo->nof;
	pthread_mutex_init(ptr->print, NULL);
	pthread_mutex_init(ptr->save, NULL);
	pthread_mutex_init(ptr->tcheck, NULL);
	philo->ptr = ptr;
	while (i < philo->nof)
	{
		philo[i].nof = x;
		philo[i].forks = forks;
		minihelp(av, ptr, &philo[i], i);
		little(ac, &philo[i], av, i);
		if (philo[i].ttd == -1 || philo[i].tts == -1 || philo[i].tte == -1)
			return (-1);
		i++;
	}
	return (0);
}
