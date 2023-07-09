/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:34:54 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/01 22:43:00 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

typedef struct s_input {
	int	nbr_of_pils;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_input;

typedef struct s_mutexes {
	pthread_mutex_t	*forks;
	pthread_mutex_t	dinner;
	pthread_mutex_t	fd;
	pthread_mutex_t	hunger;
	pthread_mutex_t	life;
	pthread_mutex_t	time_passed;
}	t_mutexes;

typedef struct s_chef {
	int					dinner_is_over;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dinner;
	pthread_mutex_t		fd;
	pthread_mutex_t		hunger;
	pthread_mutex_t		life;
	pthread_mutex_t		time;
	pthread_t			chef;
	struct s_input		input;
	struct s_pil		*pils;
	unsigned long		start_time;
	unsigned long		time_passed;
}	t_chef;

typedef struct s_pil {
	int					dinner_is_over;
	int					meals_eaten;
	int					last_meal;
	int					nbr;
	pthread_mutex_t		*fork_spoon;
	pthread_mutex_t		*fork_knife;
	pthread_mutex_t		dinner;
	pthread_mutex_t		fd;
	pthread_mutex_t		hunger;
	pthread_mutex_t		life;
	pthread_mutex_t		time;
	pthread_t			pil;
	struct s_input		input;
	unsigned long		start_time;
	unsigned long		time_passed;
}	t_pil;

//init
t_chef					*init_chef(int argc, char *argv[]);
t_input					get_input(int argc, char *argv[]);
t_pil					init_philo(int index, t_chef *chef);
void					start_dinner(t_chef *chef, int argc);

//philo_functions
void					eat(t_pil philo);
void					slip(t_pil philo);
void					think(t_pil philo);

int						can_i_do_it(t_pil philo);
void					stop_dinner(t_chef *chef, int who_died);
unsigned long			get_time(void);
void					*chef_routine(void *addr);
void					*z_routine(void *addr);
void					fre_e(t_chef *chef);

#endif