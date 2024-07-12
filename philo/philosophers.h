/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:40:30 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/12 13:07:08 by bvelasco         ###   ########.fr       */
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
# define MTX_START 1
# define MTX_LOG 0
# define LIMIT_TIME 1
# define EAT_TIME 2
# define SLEEP_TIME 3
# define MAX_EAT 4

// non philo class typedefs
typedef struct s_fork
{
	pthread_mutex_t	mtx;
	int				owner;
	__int8_t		islast;
}				t_fork;

//push forks in hands, hands is a pointer to philosopher's hands
// Philo class
typedef enum e_action
{
	THINK,
	FORK,
	EAT,
	SLEEP,
	DEAD
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
t_philo		*new_philo(t_fork *left_fork, t_fork *right_fork,
				pthread_mutex_t *mtx[], time_t c_data[]);

//forks

// unlock forks from this->hands

//constructor
t_fork		*create_forks(int forks);

void		put_down_forks(t_philo *this);
// lock two forks and put in this->hands, returns 0 if success, 1 if cannot.
__uint8_t	get_forks_pair(t_philo *this);
__uint8_t	get_forks_odd(t_philo *this);
// End of philo class
time_t		get_miliseconds(void);
short		ft_log(t_philo *philo, t_action action);
#endif
