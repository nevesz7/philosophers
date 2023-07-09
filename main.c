/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:34:58 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 20:09:01 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_chef		*chef;

	chef = init_chef(argc, argv);
	if (chef == MUTS)
		exit(0);
	fre_e(chef);
}
