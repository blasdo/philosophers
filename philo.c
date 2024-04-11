/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:00:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/11 18:17:23 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// begin of philo class

short	p_sleep(t_philo *this, time_t time)
{
	int miliseconds;

	miliseconds = get_miliseconds();
	while (miliseconds < time
			&& miliseconds - this->timestamp < *(this->limit_time))
		miliseconds = get_miliseconds();
	if (miliseconds - this->timestamp >= *(this->limit_time))
		return (1);
	return (0);
}

short	eat(t_philo *this)
{
	int	miliseconds;

	while (lock_forks(this->forks) != 0)
	{
		if (miliseconds  - this->timestamp >= this->limit_time)
			return 1;
	}
	miliseconds = get_miliseconds();
	if (miliseconds - this->timestamp >= *(this->limit_time))
		return (1);
	this->timestamp = get_miliseconds();
	return (p_sleep(this, *(this->eat_time)));
}

void	think(t_philo *this)
{
	short isalive;
	
	isalive = 1;
	while (isalive)
	{
		ft_log(this->philo_id, think);
		eat(this);
		p_sleep(this, this->sleep_time);
	}
	return ;
}
// end of philo class
void start_philo(t_philo *this)
{
	pthread_mutex_lock(this->start_mtx);
	pthread_mutex_unlock(this->start_mtx);
	think(this);
}
t_philo	*new_philo(t_fork *forks, pthread_mutex_t *mtx[], time_t *c_data[])
{
	static __u_int	philo_id = 1;
	t_philo *philo;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->philo_id = philo_id;
	philo->limit_time = c_data[LIMIT_TIME];
	philo->sleep_time = c_data[SLEEP_TIME];
	philo->eat_time = c_data[EAT_TIME];
	philo->forks = forks;
	philo->log_mtx = mtx[MTX_LOG];
	pthread_create(philo->thread, NULL, start_philo, philo);
	return (philo);
}