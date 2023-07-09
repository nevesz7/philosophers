/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:52:03 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/08 23:38:40 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

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

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	value = 0;
	if (nptr[i] == '+')
		i++;
	len = philo_strlen(nptr);
	while (i <= len && nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	return (value);
}

int	philo_strisdigit(const char *str)
{
	if (*str == '+')
		str++;
	if (!*str)
		return (FALSE);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}
