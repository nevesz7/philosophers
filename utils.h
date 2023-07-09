/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:15:45 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 20:08:18 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				philo_atoi(const char *nptr);
int				philo_strlen(const char *str);
int				philo_strisdigit(const char *str);
int				philo_strncmp(const char *s1, const char *s2, int n);
unsigned long	get_time(void);

#endif