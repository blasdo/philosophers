/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:04:28 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/24 14:43:58 by bvelasco         ###   ########.fr       */
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

short	ft_satoi(char *num, long *integer)
{
	long	i;
	short	digit;

	i = 0;
	if (!num ||!integer)
		return (ERRNULL);
	*integer = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (ERRFORM);
		if (*integer * 10 < integer)
			return (ERROVFW);
		*integer *= 10;
		digit = num[i] - '0';
		if (*integer + digit < integer)
			return (ERROVFW);
		*integer += num[i] - '0';
		i++;
	}
	return (0);
}
