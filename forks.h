/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:50:15 by bvelasco          #+#    #+#             */
/*   Updated: 2024/07/04 17:45:59 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*create_forks(unsigned long forks)
{
	t_fork			*result;
	unsigned long	i;

	result = malloc(sizeof(t_fork) * forks);
	if (!result)
		return (NULL);
	i = 0;
	while (i < forks)
		result[i].islocked = 0;
	return (result);
}