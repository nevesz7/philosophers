/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:42:28 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/02 21:32:09 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int count = 0;


void	*philife(void *value)
{
	int	*i;
	
	i = (int *)value;
	printf("i = %d\n", *i);
	return i;
}


int	philo(int amount)
{
	pthread_t	*philoshopers;
	int			i;

	i = -1;

	philoshopers = (pthread_t *)malloc(sizeof(pthread_t) * (amount + 1));
	// printf("amount = %d\n", amount);
	while (++i < amount)
	{
		// printf("nbr = %d\n", i);
		pthread_create(&philoshopers[i], NULL, &philife, &i);
	}
	while (--i > 0)
		if (!pthread_join(philoshopers[i], NULL))
			return (i * -1);
	return i;
}
