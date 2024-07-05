/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:00:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/05 18:19:24 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// begin of philo class

void	p_sleep(t_philo *this, time_t time)
{
	time_t miliseconds;

	miliseconds = get_miliseconds();
	if (this->timestamp + this->limit_time < miliseconds + time)
	{
		usleep((this->timestamp + this->limit_time - miliseconds) * 1000);
		this->isalive = 0;
	}
		usleep(time * 1000);
}

void	eat(t_philo *this)
{
	int	miliseconds;

	miliseconds = get_miliseconds();
	get_forks(this);
	miliseconds = get_miliseconds();
	if (miliseconds - this->timestamp >= this->limit_time)
		return ((void) (this->isalive = 0));
	this->timestamp = get_miliseconds();
	p_sleep(this, this->eat_time);
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

t_philo	*new_philo(t_fork *forks, pthread_mutex_t *mtx[], time_t *c_data)
{
	static __u_int	philo_id = 1;
	t_philo *philo;
	
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (0);
	philo->isalive = 1;
	philo->philo_id = philo_id++;
	philo->limit_time = c_data[LIMIT_TIME];
	philo->sleep_time = c_data[SLEEP_TIME];
	philo->eat_time = c_data[EAT_TIME];
	philo->forks = forks;
	philo->hands = ft_calloc(2, sizeof(void *));
	philo->log_mtx = mtx[MTX_LOG];
	philo->start_mtx = mtx[MTX_START];
	philo->thread = NULL;
	pthread_create(philo->thread, NULL, start_philo, philo);
	return (philo);
}
// end of philo class

void	clear_philo(t_philo *this)
{
	free(this->hands[0]);
	free(this->hands[1]);
	free(this);
}

//	start the philo
void *start_philo(void *this)
{
	t_philo *phil;

	phil = this;
	pthread_mutex_lock(phil->start_mtx);
	pthread_mutex_unlock(phil->start_mtx);
	think(this);
	clear_philo(phil);
	return (0);
}
