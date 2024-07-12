/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/12 14:44:55 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

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
		pthread_join(philos[i]->thread, NULL);
		pthread_detach(philos[i]->thread);
		free(philos[i]);
		i++;
	}
	free(philos);
}

int	main(int argc, char *argv[])
{
	ssize_t			i;
	t_philo			**philos;
	t_fork			*forks;
	ssize_t			*argi;
	pthread_mutex_t	log_mtx;

	argi = parse_args(argc, argv);
	if (!argi || argi[0] == 0)
		return (printf("ERROR PARSING ARGUMENTS\n"), 1);
	pthread_mutex_init(&log_mtx, NULL);
	philos = malloc(sizeof(void *) * argi[0]);
	forks = create_forks((argi[0]));
	i = 0;
	while (i < argi[0] - 1)
	{
		philos[i] = new_philo(&forks[i], &forks[i + 1], &log_mtx,
				(time_t *)argi);
		i++;
	}
	philos[i] = new_philo(&forks[i], &forks[0], &log_mtx, (time_t *) argi);
	wait_philos(philos, argi[0]);
	return (free(argi), free(forks), 0);
}
