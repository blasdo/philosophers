/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:04:57 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/19 14:14:29 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts the ASCII character string "num" into an integer.
 * The resulting integer will be stored in the location pointed 
 * 		to by the integer pointer.
 * Returns 0 if there are no errors; otherwise, returns the error code
 */
int	ft_satoi(char *num, int *integer);