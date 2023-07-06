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
	struct s_input	input;
	u_long			start_time;
	pthread_mutex_t	*forks;
	struct s_pil	*pils;
	pthread_t		chef;
}	t_chef;

typedef struct s_pil {
	pthread_t	pil;
	pthread_mutex_t	*forks;
	u_long			start_time;
	struct s_input	input;
	int				last_meal;
	int				namumber;
	//stuff every philo needs to eat and die happily
}	t_pil;

t_input			get_input(int argc, char *argv[]);
t_chef			*init_chef(int argc, char *argv[]);
u_long			get_time(void);

#endif