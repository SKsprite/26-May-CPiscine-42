/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:17:29 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/07 17:44:53 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_SIZE 9

int	count_visible_line(int *line, int size_of_map)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < size_of_map)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	is_valid_row_value(int grid[MAX_SIZE][MAX_SIZE], int row, int value,
		int size_of_map)
{
	int	col;

	col = 0;
	while (col < size_of_map)
	{
		if (grid[row][col] == value)
			return (0);
		col++;
	}
	return (1);
}

int	is_valid_col_value(int grid[MAX_SIZE][MAX_SIZE], int col, int value,
		int size_of_map)
{
	int	row;

	row = 0;
	while (row < size_of_map)
	{
		if (grid[row][col] == value)
			return (0);
		row++;
	}
	return (1);
}

int	check_row(int grid[MAX_SIZE][MAX_SIZE], int row, int size_of_map,
		int clues[4][MAX_SIZE])
{
	int	line[MAX_SIZE];
	int	reverse[MAX_SIZE];
	int	i;

	i = 0;
	while (i < size_of_map)
	{
		line[i] = grid[row][i];
		reverse[i] = grid[row][size_of_map - 1 - i];
		i++;
	}
	if (count_visible_line(line, size_of_map) != clues[2][row])
		return (0);
	if (count_visible_line(reverse, size_of_map) != clues[3][row])
		return (0);
	return (1);
}

int	check_col(int grid[MAX_SIZE][MAX_SIZE], int col, int size_of_map,
		int clues[4][MAX_SIZE])
{
	int	line[MAX_SIZE];
	int	reverse[MAX_SIZE];
	int	i;

	i = 0;
	while (i < size_of_map)
	{
		line[i] = grid[i][col];
		reverse[i] = grid[size_of_map - 1 - i][col];
		i++;
	}
	if (count_visible_line(line, size_of_map) != clues[0][col])
		return (0);
	if (count_visible_line(reverse, size_of_map) != clues[1][col])
		return (0);
	return (1);
}
