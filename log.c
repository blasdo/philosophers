/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:28:15 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/24 14:44:36 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short	ft_log(t_philo *philo, t_action action)
{
	printf("%i %i\n", philo->id, action);
	return (0);
}