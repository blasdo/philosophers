/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:04:28 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/20 11:08:38 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_satoi(char *num, int *integer)
{
	int	i;

	i = 0;
	if (!num ||!integer)
		return (ERRNULL);
	*integer = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (ERRFORM);
		*integer *= 10;
		*integer += num[i] - '0';
		i++;
	}
	return (0);
}
