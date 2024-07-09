/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/09 14:20:21 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

pthread_mutex_t	**create_basic_mutexs()
{
	pthread_mutex_t	**result;
	__uint8_t		i;

	result = malloc(2 * sizeof(void *));
	if (!result)
		return (0);
	i = 0;
	while (i < 2)
	{
		result[i] = malloc(1 * sizeof(pthread_mutex_t));
		pthread_mutex_init(result[i], NULL);
	}
	return (result);
}

size_t	*parse_args(int argc, char **argv)
{
	__uint8_t 	i;
	size_t		*argi;
	
	argi = malloc(5 * sizeof(size_t));
	if (!argi)
		return (NULL);
	if (argc < 5 || argc > 6)
		return (free(argi), NULL);
	i = 1;
	while (i < argc)
	{
		if(ft_satoul(argv[i], &argi[i - 1]))
			return (printf("INVALID FORMAT\n"), NULL);
		i++;
	}
	i = 0;
	while (i < argc - 1)
		printf("ARG: %lu\n", argi[i++]);
	return (argi);
}
int	main(int argc, char *argv[])
{
	size_t			i;
	t_philo			**philos;
	t_fork			*forks;
	size_t			*argi;
	pthread_mutex_t	**external;

	argi = parse_args(argc, argv);
	if (!argi)
		return(printf("ERROR PARSING ARGUMENTS\n"), 1);
	external = create_basic_mutexs();
	philos = malloc(sizeof(void *) * argi[0]);
	forks = malloc(sizeof(void *) * argi[0] * 2);
	i = 0;
	pthread_mutex_lock(external[MTX_START]);
	while (i < argi[0])
	{
		philos[i++] = new_philo(forks, external, (time_t *) &argi[1]);
		pthread_join((philos[i]->thread), NULL);
	}
	pthread_mutex_unlock(external[MTX_START]);
	return (0);
}
