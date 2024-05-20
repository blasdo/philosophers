/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:04:57 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/20 09:53:45 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "philosophers.h"
/* Converts the ASCII character string "num" into an integer.
 * The resulting integer will be stored in the location pointed 
 * 		to by the integer pointer.
 * Returns 0 if there are no errors; otherwise, returns the error code
 */
int	ft_satoi(char *num, int *integer);
#endif