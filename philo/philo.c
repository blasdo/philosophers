/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:00:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/12 14:39:45 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// begin of philo class

void	p_sleep(t_philo *this, time_t time)
{
	time_t	miliseconds;

	if (!this->isalive)
		return ;
	miliseconds = get_miliseconds();
	if (this->timestamp + this->limit_time < miliseconds + time)
	{
		usleep(((this->timestamp + this->limit_time - miliseconds) * 1000));
		ft_log(this, DEAD);
	}
	else
		usleep(time * 1000);
}

void	eat(t_philo *this)
{
	time_t		miliseconds;
	__uint8_t	fork_res;

	miliseconds = get_miliseconds();
	fork_res = 1;
	while (fork_res)
	{
		miliseconds = get_miliseconds();
		if (miliseconds - this->timestamp >= this->limit_time)
			return ((void)(ft_log(this, DEAD)));
		if (this->philo_id % 2)
			fork_res = get_forks_pair(this);
		else
			fork_res = get_forks_odd(this);
	}
	this->timestamp = get_miliseconds();
	ft_log(this, EAT);
	p_sleep(this, this->eat_time);
	put_down_forks(this);
}

void	think(t_philo *this)
{
	while (this->isalive && this->max_eat)
	{
		ft_log(this, THINK);
		eat(this);
		ft_log(this, SLEEP);
		p_sleep(this, this->sleep_time);
		if (this->max_eat > 0)
			(this->max_eat)--;
	}
	return ;
}

t_philo	*new_philo(t_fork *left_fork, t_fork *right_fork,
		pthread_mutex_t **mtx, time_t *c_data)
{
	static __u_int	philo_id = 1;
	t_philo			*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (0);
	philo->isalive = 1;
	philo->philo_id = philo_id++;
	philo->limit_time = c_data[LIMIT_TIME];
	philo->sleep_time = c_data[SLEEP_TIME];
	philo->eat_time = c_data[EAT_TIME];
	philo->max_eat = c_data[MAX_EAT];
	philo->log_mtx = mtx[MTX_LOG];
	philo->start_mtx = mtx[MTX_START];
	philo->hands[0] = left_fork;
	philo->hands[1] = right_fork;
	pthread_create(&philo->thread, NULL, start_philo, philo);
	return (philo);
}
// end of philo class

//	start the philo
void	*start_philo(void *this)
{
	t_philo	*phil;

	phil = this;
	phil->init_ts = get_miliseconds();
	phil->timestamp = phil->init_ts;
	think(this);
	return ((void *)0);
}
