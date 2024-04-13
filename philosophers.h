/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/13 14:55:19 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h>
# define MTX_START 1
# define MTX_LOG 0
# define LIMIT_TIME 0
# define SLEEP_TIME 1
# define EAT_TIME 2

// non philo class typedefs
typedef struct s_fork
{
	pthread_mutex_t *mtx;
	__int8_t 		islocked;
}				t_fork;
//push forks in hands, hands is a pointer to philosopher's hands
void	get_forks(t_forks *forks, t_forks **hands[]);
// Philo class
typedef enum e_action
{
	THINK,
	EAT,
	SLEEP,
	DEAD
}			t_action;

typedef struct s_philo
{
	pthread_t		*thread;
	time_t			timestamp;
	__u_int			philo_id;
	const time_t	*limit_time;
	const time_t	*sleep_time;
	const time_t	*eat_time;
	t_fork			*forks;
	pthread_mutex_t	*log_mtx;
	pthread_mutex_t *start_mtx;
}				t_philo;

short	p_sleep(t_philo *this, time_t time);
short	eat(t_philo *this);
void	think(t_philo *this);
t_philo	*new_philo(t_fork *forks, pthread_mutex_t **mtx, time_t *c_data[]);
// End of philo class
time_t	get_miliseconds(void);
short	ft_log(t_philo *philo, t_action action);
#endif
