/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:14:55 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/07 11:38:07 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_SIZE 9

void	init_grid(int grid[MAX_SIZE][MAX_SIZE], int size_of_map)
{
	int	row;
	int	col;

	row = 0;
	while (row < size_of_map)
	{
		col = 0;
		while (col < size_of_map)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_grid(int grid[MAX_SIZE][MAX_SIZE], int size_of_map)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < size_of_map)
	{
		col = 0;
		while (col < size_of_map)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < size_of_map - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
