/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:00:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/03 12:43:54 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// begin of philo class

short	p_sleep(t_philo *this, time_t time)
{
	int miliseconds;

	miliseconds = get_miliseconds();
	while (miliseconds < time
			&& miliseconds - this->timestamp < this->limit_time)
		miliseconds = get_miliseconds();
	if (miliseconds - this->timestamp >= this->limit_time)
		return (1);
	return (0);
}

short	eat(t_philo *this)
{
	int	miliseconds;

	miliseconds = get_miliseconds();
	while (lock_forks(this->forks) != 0)
	{
		if (miliseconds  - this->timestamp >= this->limit_time)
			return 1;
	}
	miliseconds = get_miliseconds();
	if (miliseconds - this->timestamp >= this->limit_time)
		return (1);
	this->timestamp = get_miliseconds();
	return (p_sleep(this, this->eat_time));
}

void	think(t_philo *this)
{
	while (this->isalive)
	{
		ft_log(this, THINK);
		eat(this);
		ft_log(this, SLEEP);
		p_sleep(this, this->sleep_time);
	}
	return ;
}

void *start_philo(void *this);
t_philo	*new_philo(t_fork *forks, pthread_mutex_t *mtx[], time_t *c_data)
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
	philo->start_mtx = mtx[MTX_START];
	philo->thread = NULL;
	pthread_create(philo->thread, NULL, start_philo, philo);
	return (philo);
}
// end of philo class

void *start_philo(void *this)
{
	t_philo *phil;

	phil = this;
	pthread_mutex_lock(phil->start_mtx);
	pthread_mutex_unlock(phil->start_mtx);
	think(this);
	return (0);
}
