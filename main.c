/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/02 12:39:07 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

int	main(int argc, char *argv[])
{

	printf("%li", get_miliseconds());
	/*
	int		i;
	long	argi[5];
	t_philo **philos;
	t_fork	*forks;
	pthread_mutex_t	external[3];

	pthread_mutex_init(&external[0], NULL);
	pthread_mutex_init(&external[1], NULL);
	i = 1;
	if (argc <= 4 || argc > 6)
		return (1);
	if (argc < 6)
		argi[4] = -1;
	while (i < argc)
	{
		if(ft_satoi(argv[i], &argi[i - 1]))
			return (ERRFORM);
		i++;
	}
	i = 0;
	while (i < argi[0])
	{
		philos[i] = new_philo(forks, external, (time_t *) &argi[1]);
	}
	return (0);*/
}