/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/11 15:58:27 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h>

// non philo class typedefs
typedef int8_t t_fork;
// Philo class
typedef enum e_action
{
	THINK,
	EAT,
	SLEEP
}			t_action;

typedef struct s_philo
{
	pthread_t		*thread;
	time_t			timestamp;
	time_t			philo_id;
	t_fork			*forks;
	const time_t	*limit_time;
	const time_t	*sleep_time;
	const time_t	*eat_time;
	pthread_mutex_t	*write_mtx;
	pthread_mutex_t	*dead_mtx;
	pthread_mutex_t	**forks_mutex;
}				t_philo;

short	p_sleep(t_philo *this, time_t time);
short	eat(t_philo *this);
void	think(t_philo *this);
t_philo	*new_philo(pthread_mutex_t *write_mtx, pthread_mutex_t *dead,
			pthread_mutex_t **forks);
// End of philo class
time_t	get_miliseconds(void);
void	ft_log(t_philo *philo, t_action action, pthread_mutex_t *mtx);
#endif