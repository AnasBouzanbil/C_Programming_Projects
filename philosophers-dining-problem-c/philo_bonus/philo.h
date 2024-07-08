/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:26:11 by abouzanb          #+#    #+#             */
/*   Updated: 2023/02/04 00:26:13 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <stdatomic.h>

typedef struct t_bonus
{
	int			nof; // number of philos
	int			id; // id of the philo 
	int			ttd;	// time to die
	int			tts;
	int			tte;
	long		time;
	atomic_long	last_meal; // time when the philo has eaten for the last time I used Atocmic in order to avoid data race
	atomic_int	number_of_meals; 
	atomic_int	count; 
	sem_t		*sem; // semaphore to take the forks and this semaphore is shared between all the philos
	sem_t		*print; // semaphore to print the state of the philo and the time. and this mutex is shared between all the philos
	pthread_t	pid; // thread of the philo
}t_philo;

int		ft_atoi(const char *s);
void	ft_usleep(long time);
long	the_time(void);
int		parsing(char *av[]);
void	*function(void *ptr);
void	state_change(t_philo *str, char *state);
int		init(char *av[], t_philo **philo, sem_t *sem);
int		get(char *av[], t_philo *philo, int x, sem_t *sem);
#endif
