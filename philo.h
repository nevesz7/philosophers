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

typedef struct s_philo {
	int				*input;
	u_long			start_time;
	pthread_mutex_t	*forks;
}	t_philo;


int				philo(int amount);
t_philo			*init_philo(int argc, char *argv[]);
u_long			get_time(void);
void			*philife(void *value);

#endif