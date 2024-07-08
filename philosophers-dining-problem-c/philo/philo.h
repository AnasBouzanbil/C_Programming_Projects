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

typedef struct s_struct //  structure to save the mutexes
{
	pthread_mutex_t	*print; // mutex to print the state of the philo and the time. and this mutex is shared between all the philos
	pthread_mutex_t	*save; 
	pthread_mutex_t	*tcheck;
}t_struct;
typedef struct s_phil
{
	pthread_mutex_t	*forks; // mutex to take the forks and this table of mutex is shared between all the philos
	pthread_mutex_t	*save;
	pthread_mutex_t	*print;
	pthread_mutex_t	*tcheck;
	int				id_left; // id of the left fork of the philo 
	int				check; // to check if the philo is dead or not
	int				all; // to check if all the philos have eaten or not 
	int				number_of_eat; // number of time the philo has eaten 
	int				id; // id of the philo 
	int				idn; 
	int				ttd; // time to die
	int				tts; // time to sleep
	int				tte; // time to eat
	long			time; // time when the philo has started to eat 
	long			last_meal; // time when the philo has eaten for the last time 
	long			current_time; // current time
	int				nof; 
	int				nop;
	pthread_t		pid;
	t_struct		*ptr;
}t_philo;

int		ft_atoi(const char *s);
int		f(t_philo *str, int *all);
long	the_time(void); // to get the current time using gettimeofday
void	ft_usleep(long time); // to sleep for a specific time using usleep
void	*function(void *ptr); // the function that the philo will execute
int		parsing(char *av[]); // to check if the arguments are valid or not
void	state_change(t_philo *str, char *state); // to print the state of the philo
int		get_that(char *av[], pthread_mutex_t *forks, t_philo *philo, int ac); 
void	do_help(t_philo *str);
int		initi(char *av[], pthread_mutex_t **forks, t_philo **philo, int ac);
void	get_init(pthread_mutex_t *forks, t_philo *philo);
#endif
