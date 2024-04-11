/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:00:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/11 16:00:52 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short	p_sleep(t_philo *this, time_t time)
{
	int miliseconds;

	miliseconds = get_miliseconds();
	while (miliseconds < time && miliseconds < *(this->limit_time))
		miliseconds = get_miliseconds();
	if (miliseconds >= *(this->limit_time))
		return (1);
	return (0);
}

short	eat(t_philo *this)
{
	int	miliseconds;

	miliseconds = get_miliseconds();
	if (miliseconds >= *(this->limit_time))
		return (1);
	this->timestamp = get_miliseconds();
	return (p_sleep(this, *(this->eat_time)));
}

// not implemented
void	think(t_philo *this)
{
	return;
}

t_philo	*new_philo()