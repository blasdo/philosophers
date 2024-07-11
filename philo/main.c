/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/11 15:31:00 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

pthread_mutex_t	**create_basic_mutexs(void)
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
		i++;
	}
	return (result);
}

ssize_t	*parse_args(int argc, char **argv)
{
	__uint8_t	i;
	ssize_t		*argi;

	argi = malloc(5 * sizeof(size_t));
	if (!argi)
		return (NULL);
	if (argc < 5 || argc > 6)
		return (free(argi), NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_satoul(argv[i], &argi[i - 1]))
			return (printf("INVALID FORMAT\n"), NULL);
		i++;
	}
	if (argc == 5)
		argi[4] = -1;
	return (argi);
}

void	wait_philos(t_philo **philos, size_t	number_of_philos)
{
	size_t	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_join(philos[i++]->thread, NULL);
	}
}

int	main(int argc, char *argv[])
{
	ssize_t			i;
	t_philo			**philos;
	t_fork			*forks;
	ssize_t			*argi;
	pthread_mutex_t	**external;

	argi = parse_args(argc, argv);
	if (!argi || argi[0] == 0)
		return (printf("ERROR PARSING ARGUMENTS\n"), 1);
	external = create_basic_mutexs();
	philos = malloc(sizeof(void *) * argi[0]);
	forks = create_forks((argi[0]));
	i = 0;
	pthread_mutex_lock(external[MTX_START]);
	while (i < argi[0] - 1)
	{
		philos[i] = new_philo(&forks[i], &forks[i + 1], external,
				(time_t *)argi);
		i++;
	}
	philos[i] = new_philo(&forks[i], &forks[0], external, (time_t *) argi);
	pthread_mutex_unlock(external[MTX_START]);
	wait_philos(philos, argi[0]);
	return (0);
}
