/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:41:40 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 13:56:25 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	val;
	int	i;

	if (min >= max)
		return (0);
	val = (max - min);
	i = 0;
	arr = malloc(sizeof(int) * val);
	while (i < val)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
