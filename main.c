/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:01:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/19 14:03:45 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_blueprint(t_philo *blueprint, int argc, char *argv[])
{

}

int	main(int argc, char *argv[])
{
	t_philo	blueprint;
	t_philo **philos;

	if (!init_blueprint(&blueprint, argc, argv))
		return (1);
}