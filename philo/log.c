/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:28:15 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/13 13:19:09 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short	ft_log(t_philo *philo, t_action action)
{
	static short	can_print = 1;
	const char		*s_actions[6] = {"is thinking", "has taken a fork",
		"is eating", "is sleeping", "died", "has left a fork"};

	if (!philo->isalive)
		return (0);
	pthread_mutex_lock(philo->log_mtx);
	if (can_print)
	{
		printf("%li %i %s\n",
			get_miliseconds() - philo->init_ts,
			philo->philo_id, s_actions[action]);
		if (action == DEAD)
		{
			philo->isalive = 0;
			can_print = 0;
		}
	}
	else
		philo->isalive = 0;
	pthread_mutex_unlock(philo->log_mtx);
	return (0);
}
