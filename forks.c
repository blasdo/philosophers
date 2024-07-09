/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:49:45 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/09 17:56:41 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

__uint8_t	get_forks(t_philo *this)
{
	t_fork		*forks;
	__uint8_t	hand;
	int			i;

	i = 0;
	hand = 0;
	while(!(forks[i].islast && hand < 2))
	{
		pthread_mutex_lock(forks->mtx);
		if (!forks[i].islocked)
		{
			this->hands[hand] = forks + i;
			forks[i].islocked = 1;
		}
		pthread_mutex_unlock(forks[i].mtx);
		i++;
	}
	if (hand == 2)
		return (0);
	this->hands[0] = NULL;
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
		pthread_mutex_init(result[i].mtx, NULL);
		result[i].islocked = 0;
		result[i].islast = 0;
	}
	result[++i].islast = 0;
	return (result);
}