/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:49:58 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 20:06:42 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "philo.h"

int	should_we_stop(t_chef *chef)
{
	int				i;
	int				we_should;
	unsigned long	time;

	i = -1;
	we_should = NO_ONE;
	while (++i < chef->input.nbr_of_pils)
	{
		pthread_mutex_lock(&chef->life);
		time = (get_time() - chef->pils[i].last_meal[0]);
		if (time > (u_long)chef->input.time_to_die)
		{
			pthread_mutex_unlock(&chef->life);
			return (chef->pils[i].nbr);
		}
		pthread_mutex_unlock(&chef->life);
		pthread_mutex_lock(&chef->hunger);
		if (chef->pils[i].meals_eaten != chef->input.times_must_eat)
			we_should = FALSE;
		pthread_mutex_unlock(&chef->hunger);
	}
	if (we_should == NO_ONE)
		pthread_mutex_lock(&chef->fd);
	usleep(7000);
	return (we_should);
}

void	*chef_routine(void *addr)
{
	t_chef	*kitchen;
	int		who_died;

	kitchen = addr;
	while (1)
	{
		who_died = should_we_stop(kitchen);
		if (who_died != FALSE)
			break ;
	}
	pthread_mutex_lock(&kitchen->dinner);
	if (who_died != NO_ONE && who_died != FALSE)
		lights_camera_action(who_died, kitchen->start_time, DIED, &kitchen->fd);
	kitchen->dinner_is_over = TRUE;
	pthread_mutex_unlock(&kitchen->dinner);
	if (who_died == NO_ONE)
		pthread_mutex_unlock(&kitchen->fd);
	return (MUTS);
}
