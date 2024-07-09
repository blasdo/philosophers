/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/09 17:59:56 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "utils.h"
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
	__int8_t		islocked:4;
	__int8_t		islast:4;
}				t_fork;

//push forks in hands, hands is a pointer to philosopher's hands

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
	pthread_t			thread;
	__uint16_t			philo_id;
	__uint16_t			max_eat;
	time_t				timestamp;
	time_t				limit_time;
	time_t				sleep_time;
	time_t				eat_time;
	t_fork				*forks;
	t_fork				*hands[2];
	pthread_mutex_t		*log_mtx;
	pthread_mutex_t		*start_mtx;
}						t_philo;

// white time or until philo dies.
void		p_sleep(t_philo *this, time_t time);
void		eat(t_philo *this);
void		lock_forks(t_fork *forks);
void		think(t_philo *this);
void		*start_philo(void *this);
t_philo		*new_philo(t_fork *forks, pthread_mutex_t *mtx[], time_t c_data[]);
__uint8_t	get_forks(t_philo *this);
// End of philo class
time_t	get_miliseconds(void);
short	ft_log(t_philo *philo, t_action action);
#endif
