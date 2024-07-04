/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/04 18:24:23 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# define ERRMEMO 1
# define ERRNULL 2
# define ERRFORM 3
# define ERROVFW 4
# define MTX_START 1
# define MTX_LOG 0
# define LIMIT_TIME 0
# define SLEEP_TIME 1
# define EAT_TIME 2

// non philo class typedefs
typedef struct s_fork
{
	pthread_mutex_t	*mtx;
	__int8_t		islocked;
}				t_fork;

//push forks in hands, hands is a pointer to philosopher's hands
void	get_forks(t_fork *forks, t_fork **hands[]);
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
	__uint8_t			isalive;
	pthread_t			*thread;
	__uint16_t			philo_id;
	__uint16_t			max_eat;
	time_t				timestamp;
	time_t				limit_time;
	time_t				sleep_time;
	time_t				eat_time;
	t_fork				*forks;
	pthread_mutex_t		*log_mtx;
	pthread_mutex_t		*start_mtx;
}						t_philo;

short	p_sleep(t_philo *this, time_t time);
short	eat(t_philo *this);
short	lock_forks(t_fork *forks);
void	think(t_philo *this);
t_philo	*new_philo(t_fork *forks, pthread_mutex_t *mtx[], time_t c_data[]);
// End of philo class
time_t	get_miliseconds(void);
short	ft_log(t_philo *philo, t_action action);
#endif
