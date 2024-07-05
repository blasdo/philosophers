/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/05 18:21:25 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	int				i;
	t_philo			**philos;
	t_fork			*forks;
	unsigned long	argi[5];
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
		if(ft_satoul(argv[i], &argi[i - 1]))
			return (printf("INVALID FORMAT\n"), ERRFORM);
		i++;
	}
	i = 0;
	while (i < argc - 1)
		printf("ARG: %lu\n", argi[i++]);
	i = 0;
	philos = malloc(sizeof(void *) * argi[0]);
	forks = malloc(sizeof(void *) * argi[0] * 2);
	while ((unsigned long) i < argi[0])
	{
		philos[i] = new_philo(forks, (pthread_mutex_t **)&external, (time_t *) &argi[1]);
	}
	pthread_join(*(philos[0]->thread), 0);
	return (0);
}