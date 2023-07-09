/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:49:58 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 01:08:47 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "philo.h"
#include "utils.h"

int	should_we_stop(t_chef *chef)
{
	int	i;
	int	we_should;

	i = -1;
	we_should = TRUE;
	while (++i < chef->input.nbr_of_pils)
	{
		
		pthread_mutex_lock(&chef->muts.life);
		if ((int)(get_time() - chef->pils[i].last_meal) > chef->input.time_to_die)
		{
			pthread_mutex_unlock(&chef->muts.life);
			return (chef->pils[i].nbr);
		}
		pthread_mutex_unlock(&chef->muts.life);
		pthread_mutex_lock(&chef->muts.hunger);
		if (chef->pils[i].meals_eaten < chef->input.times_must_eat)
			we_should = FALSE;
		pthread_mutex_unlock(&chef->muts.hunger);
	}
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
		if (who_died)
			break ;
	}
	pthread_mutex_lock(&kitchen->muts.dinner);
	kitchen->dinner_is_over = TRUE;
	pthread_mutex_unlock(&kitchen->muts.dinner);
	stop_dinner(kitchen, who_died);
	return (NULL);
}
