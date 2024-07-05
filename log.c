/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:28:15 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/05 14:08:40 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short	ft_log(t_philo *philo, t_action action)
{
	static	short	can_print = 1;

	pthread_mutex_lock(philo->log_mtx);
	if (can_print)
		printf("%i %i\n", philo->philo_id, action);
	else
		philo->isalive = 0;
	if (action == DEAD)
		can_print = 0;
	pthread_mutex_unlock(philo->log_mtx);
	return (0);
}