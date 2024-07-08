/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:08:26 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/07 17:49:41 by abouzanb         ###   ########.fr       */
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
		p->all = 0;
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

int	get_that(char *av[], pthread_mutex_t *forks, t_philo *philo, int ac) // to get the arguments
{
	int				i;
	t_struct		*ptr;
	int				x;

	ptr = malloc(sizeof(t_struct)); // to allocate the structure of the mutexes 
	ptr->save = malloc(sizeof(pthread_mutex_t));
	ptr->tcheck = malloc(sizeof(pthread_mutex_t));
	ptr->print = malloc(sizeof(pthread_mutex_t));
	i = 0;
	x = philo->nof; // to save the number of philos
	pthread_mutex_init(ptr->print, NULL); // to initialize the mutexes 
	pthread_mutex_init(ptr->save, NULL); // to initialize the mutexes
	pthread_mutex_init(ptr->tcheck, NULL); 
	philo->ptr = ptr; // to save the structure of the mutexes in the structure of the philo
	while (i < philo->nof)
	{
		philo[i].nof = x; // to save the number of philos in the structure of the philo 
		philo[i].forks = forks; // to save the table of mutexes in the structure of the philo 
		minihelp(av, ptr, &philo[i], i); // to save the arguments in the structure of the philo
		little(ac, &philo[i], av, i); // to save the arguments in the structure of the philo
		if (philo[i].ttd == -1 || philo[i].tts == -1 || philo[i].tte == -1) // if the user has entered a negative number 
			return (-1); // return -1
		i++; 
	}
	return (0);
}
