/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:37:01 by hshan             #+#    #+#             */
/*   Updated: 2026/06/15 14:37:02 by hshan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	minimum(int tmp[3])
{
	int	i;
	int	min;

	i = 0;
	min = tmp[0];
	while (i < 3)
	{
		if (tmp[i] < min)
			min = tmp[i];
		i++;
	}
	return (min);
}

int	dp_val(int **map, int i, int j)
{
	int	tmp[3];

	tmp[0] = map[i + 1][j];
	tmp[1] = map[i + 1][j + 1];
	tmp[2] = map[i][j + 1];
	return (minimum(tmp) + 1);
}

void	process_row(int **map, int i, int *dims, int *max)
{
	int	j;

	j = dims[1] - 1;
	while (j >= 0)
	{
		if (map[i][j] != 0)
		{
			if (i + 1 == dims[0] || j + 1 == dims[1])
				map[i][j] = 1;
			else
				map[i][j] = dp_val(map, i, j);
			if (map[i][j] > *max)
				*max = map[i][j];
		}
		j--;
	}
}

int	**biggest_sq(int **map, int size_row, int size_col, int *max)
{
	int	dims[2];
	int	i;

	dims[0] = size_row;
	dims[1] = size_col;
	i = size_row - 1;
	while (i >= 0)
	{
		process_row(map, i, dims, max);
		i--;
	}
	return (map);
}
