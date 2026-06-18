/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:48:31 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/07 18:57:42 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_SIZE 9

int	is_valid_row_value(int grid[MAX_SIZE][MAX_SIZE], int row, int value,
		int size_of_map);
int	is_valid_col_value(int grid[MAX_SIZE][MAX_SIZE], int col, int value,
		int size_of_map);
int	check_row(int grid[MAX_SIZE][MAX_SIZE], int row, int size_of_map,
		int clues[4][MAX_SIZE]);
int	check_col(int grid[MAX_SIZE][MAX_SIZE], int col, int size_of_map,
		int clues[4][MAX_SIZE]);

int	is_valid_position(int grid[MAX_SIZE][MAX_SIZE], int pos, int value,
		int size_of_map)
{
	int	row;
	int	col;

	row = pos / size_of_map;
	col = pos % size_of_map;
	if (!is_valid_row_value(grid, row, value, size_of_map))
		return (0);
	if (!is_valid_col_value(grid, col, value, size_of_map))
		return (0);
	return (1);
}

int	check_clues(int grid[MAX_SIZE][MAX_SIZE], int pos, int size_of_map,
		int clues[4][MAX_SIZE])
{
	int	row;
	int	col;

	row = pos / size_of_map;
	col = pos % size_of_map;
	if (col == size_of_map - 1
		&& !check_row(grid, row, size_of_map, clues))
		return (0);
	if (row == size_of_map - 1
		&& !check_col(grid, col, size_of_map, clues))
		return (0);
	return (1);
}

int	solve(int grid[MAX_SIZE][MAX_SIZE], int pos, int size_of_map,
		int clues[4][MAX_SIZE])
{
	int	row;
	int	col;
	int	value;

	if (pos == size_of_map * size_of_map)
		return (1);
	row = pos / size_of_map;
	col = pos % size_of_map;
	value = 1;
	while (value <= size_of_map)
	{
		if (is_valid_position(grid, pos, value, size_of_map))
		{
			grid[row][col] = value;
			if (check_clues(grid, pos, size_of_map, clues)
				&& solve(grid, pos + 1, size_of_map, clues))
				return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
