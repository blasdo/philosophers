/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/09 13:58:34 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

pthread_mutex_t	*create_basic_mutexs()
{
	pthread_mutex_t	*result;
	__uint8_t		i;

	result = malloc(3 * sizeof(pthread_mutex_t));
	if (!result)
		return (0);
	i = 0;
	while (i < 3)
	{
		pthread_mutex_init(result + i, NULL);
	}
	return (0);
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
	t_philo			**philos;
	t_fork			*forks;
	size_t			*argi;
	pthread_mutex_t	external[3];

	argi = parse_args(argc, argv);
	if (!argi)
		return(printf("ERROR PARSING ARGUMENTS\n"), 1);
	philos = malloc(sizeof(void *) * argi[0]);
	forks = malloc(sizeof(void *) * argi[0] * 2);

/*
	while ((unsigned long) i < argi[0])
	{
		philos[i] = new_philo(forks, (pthread_mutex_t **)&external, (time_t *) &argi[1]);
	}
	pthread_join((philos[0]->thread), 0);
	return (0);
	*/
}
