/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:49:45 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/16 10:49:40 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_down_forks(t_philo *this)
{
	if (this->philo_id % 2)
	{
		pthread_mutex_unlock(this->hands[0]);
		pthread_mutex_unlock(this->hands[1]);
	}
	else
	{
		pthread_mutex_unlock(this->hands[1]);
		pthread_mutex_unlock(this->hands[0]);
	}
}
void	clear_forks(pthread_mutex_t **toclear, int max_forks)
{
	int i;

	i = 0;
	if (!toclear)
		return;
	while (i < max_forks)
		free(toclear[i++]);
	free(toclear);
}
pthread_mutex_t	**create_forks(int forks)
{
	pthread_mutex_t	**result;
	int	i;

	result = malloc(sizeof(void *) * forks);
	if (!result)
		return (NULL);
	i = 0;
	while (i < forks)
	{
		result[i] = malloc(1 * sizeof(pthread_mutex_t));
		if (!result[i] || pthread_mutex_init(result[i], NULL))
			clear_forks(result, i + 1);
		i++;
	}
	return (result);
}
