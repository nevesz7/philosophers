/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:07:18 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 11:36:45 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "utils.h"

static void	philo_put_nbr(unsigned long nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
	else
	{
		philo_put_nbr(nbr / 10);
		c = (nbr % 10) + 48;
		write (1, &c, 1);
	}
}

static void	philo_put_philo(unsigned long nbr)
{
	write(1, " ", 1);
	philo_put_nbr(nbr);
	write(1, " ", 1);
}

void	lights_camera_action(int number, unsigned long start_time, char *code,
	pthread_mutex_t *fd)
{
	pthread_mutex_lock(fd);
	philo_put_nbr(get_time() - start_time);
	philo_put_philo(number);
	write(1, code, philo_strlen(code));
	pthread_mutex_unlock(fd);
}
