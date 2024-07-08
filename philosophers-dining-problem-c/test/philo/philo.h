/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:35:34 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/27 23:35:37 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct t_struct
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*save;
	pthread_mutex_t	*tcheck;
}t_struct;
typedef struct t_phil
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*save;
	pthread_mutex_t	*print;
	pthread_mutex_t	*tcheck;
	int				id_left;
	int				check;
	int				all;
	int				number_of_eat;
	int				id;
	int				idn;
	int				ttd;
	int				tts;
	int				tte;
	long			time;
	long			last_meal;
	long			current_time;
	int				nof;
	int				nop;
	pthread_t		pid;
	t_struct		*ptr;
}t_philo;

int		ft_atoi(const char *s);
int		f(t_philo *str, int *all);
long	the_time(void);
void	ft_usleep(long time);
void	*function(void *ptr);
int		parsing(char *av[]);
void	state_change(t_philo *str, char *state);
int		get_that(char *av[], pthread_mutex_t *forks, t_philo *philo, int ac);
void	do_help(t_philo *str);
int		initi(char *av[], pthread_mutex_t **forks, t_philo **philo, int ac);
void	get_init(pthread_mutex_t *forks, t_philo *philo);
#endif
