/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:55:43 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/07 17:08:12 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fre_e(t_chef *chef)
{
	free(chef->pils);
	//destroy forks
	free(chef->forks);
	free(chef);
}
