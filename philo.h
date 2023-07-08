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
# include <unistd.h>
# include <sys/time.h>
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

typedef struct s_chef {
	int				check;
	pthread_mutex_t	*forks;
	pthread_t		chef;
	struct s_input	input;
	struct s_pil	*pils;
	u_long			start_time;
}	t_chef;

typedef struct s_pil {
	int				check;
	int				last_meal;
	int				nbr;
	pthread_mutex_t	*fork_spoon;
	pthread_mutex_t	*fork_knife;
	pthread_t		pil;
	struct s_input	input;
	u_long			start_time;
	//stuff every philo needs to eat and die happily
}	t_pil;

//init
t_chef			*init_chef(int argc, char *argv[]);
t_input			get_input(int argc, char *argv[]);
t_pil			init_philo(int index, t_chef *chef);
void			start_dinner(t_chef *chef, int argc);

//philo_functions
int				eat(t_pil philo);
void			slip(t_pil philo);
void			starve(t_pil philo);
void			think(t_pil philo);

void			*chef_routine(void *addr);
void			*p_routine(void *addr);
void			fre_e(t_chef *chef);
u_long			get_time(void);

#endif