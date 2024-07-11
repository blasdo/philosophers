/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:49:45 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/11 14:58:57 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_down_forks(t_philo *this)
{
	t_fork	*right_fork;
	t_fork	*left_fork;

	right_fork = this->hands[0];
	left_fork = this->hands[1];
	pthread_mutex_lock(&left_fork->mtx);
	if (left_fork->owner == this->philo_id)
		left_fork->owner = 0;
	pthread_mutex_unlock(&left_fork->mtx);
	pthread_mutex_lock(&right_fork->mtx);
	if (right_fork->owner == this->philo_id)
		right_fork->owner = 0;
	pthread_mutex_unlock(&right_fork->mtx);
}

__uint8_t	get_forks(t_philo *this)
{
	t_fork	*right_fork;
	t_fork	*left_fork;

	right_fork = this->hands[0];
	left_fork = this->hands[1];
	pthread_mutex_lock(&left_fork->mtx);
	if (left_fork->owner == 0)
	{
		left_fork->owner = this->philo_id;
		ft_log(this, FORK);
	}
	pthread_mutex_unlock(&left_fork->mtx);
	pthread_mutex_lock(&right_fork->mtx);
	if (left_fork->owner == this->philo_id && right_fork->owner == 0)
	{
		right_fork->owner = this->philo_id;
		ft_log(this, FORK);
	}
	pthread_mutex_unlock(&right_fork->mtx);
	if (right_fork->owner == this->philo_id
		&& left_fork->owner == this->philo_id
		&& left_fork != right_fork)
		return (0);
	return (1);
}

t_fork	*create_forks(unsigned long forks)
{
	t_fork			*result;
	unsigned long	i;

	result = malloc(sizeof(t_fork) * (1 + forks));
	if (!result)
		return (NULL);
	i = 0;
	while (i < forks)
	{
		pthread_mutex_init(&result[i].mtx, NULL);
		result[i].owner = 0;
		result[i].islast = 0;
		i++;
	}
	result[i].islast = 1;
	return (result);
}