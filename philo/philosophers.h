/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/16 10:30:29 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "utils.h"
# define ERRMEMO 1
# define ERRNULL 2
# define ERRFORM 3
# define ERROVFW 4
# define MTX_LOG 0
# define LIMIT_TIME 1
# define EAT_TIME 2
# define SLEEP_TIME 3
# define MAX_EAT 4

//push forks in hands, hands is a pointer to philosopher's hands
// Philo class
typedef enum e_action
{
	THINK,
	FORK,
	EAT,
	SLEEP,
	DEAD,
	LEFT
}			t_action;

typedef struct s_philo
{
	__uint8_t			isalive;
	pthread_t			thread;
	int					philo_id;
	int					max_eat;
	time_t				timestamp;
	time_t				init_ts;
	time_t				limit_time;
	time_t				sleep_time;
	time_t				eat_time;
	pthread_mutex_t		*hands[2];
	pthread_mutex_t		*log_mtx;
}						t_philo;

// white time or until philo dies.
void			p_sleep(t_philo *this, time_t time);
void			eat(t_philo *this);
void			think(t_philo *this);
void			*start_philo(void *this);
t_philo			*new_philo(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
					pthread_mutex_t *log_mtx, time_t c_data[]);

//forks

// unlock forks from this->hands

//create all forks
pthread_mutex_t	**create_forks(int forks);
//release all forks
void			put_down_forks(t_philo *this);
// get miliseconds since January 1 1970
time_t			get_miliseconds(void);
short			ft_log(t_philo *philo, t_action action);
#endif
