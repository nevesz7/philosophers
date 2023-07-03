/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:52:03 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/02 23:11:31 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}

int	philo_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str [i])
		i++;
	return (i);
}

int	philo_atoi(const char *nptr)
{
	long int	value;
	int			i;
	int			len;
	int			sign;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	value = 0;
	sign = FALSE;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = TRUE;
		i++;
	}
	len = philo_strlen(nptr);
	while (i <= len && nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	if (sign == TRUE)
		return (-value);
	return (value);
}
