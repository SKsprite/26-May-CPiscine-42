/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:02:58 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 15:56:24 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (-1);
	}
	length = max - min;
	arr = malloc(length * sizeof(int));
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (length);
}
