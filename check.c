/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:42:58 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/02 22:08:38 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	has_error(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		throw_error(NUMBER_OF_ARGS);
		return (FALSE);
	}
	if (argv[0][0] != '.')
		return (FALSE);
	return (TRUE);
}
