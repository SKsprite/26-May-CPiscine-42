/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 04:15:05 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 04:15:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**free_map(int **map)
{
	if (!map)
		return (NULL);
	if (*map)
		free(*map);
	free(map);
	return (NULL);
}

static void	fill_sq(int **map, int row, int col, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			map[row + i][col + j] = max + 2;
			j++;
		}
		i++;
	}
}

void	normalize_map(t_checks dict)
{
	int	**map;
	int	row;
	int	col;

	map = dict.map;
	row = 0;
	while (row < dict.rows)
	{
		col = 0;
		while (col < dict.cols)
		{
			if (map[row][col] == dict.max)
			{
				fill_sq(map, row, col, dict.max);
				return ;
			}
			col++;
		}
		row++;
	}
}

static void	fill_line(char *line, int *row, t_checks dict)
{
	int	i;

	i = 0;
	while (i < dict.cols)
	{
		if (row[i] == 0)
			line[i] = dict.obs;
		else if (row[i] > dict.max)
			line[i] = dict.sqa;
		else
			line[i] = dict.emp;
		i++;
	}
}

void	print_map(t_checks dict)
{
	char	*line;
	int		**map;
	int		*row;

	map = dict.map;
	line = malloc(dict.cols + 2);
	if (!line)
		return (free_map(dict.map), (void)0);
	while (*map)
	{
		row = *map++;
		fill_line(line, row, dict);
		line[dict.cols] = '\n';
		write(STDOUT, line, dict.cols + 1);
	}
	free(line);
	free_map(dict.map);
}
