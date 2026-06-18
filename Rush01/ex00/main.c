/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:22:17 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/07 16:43:29 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_SIZE 9

void	ft_putstr(char *str);
int		get_size_from_arg(char *arg);
void	init_grid(int grid[MAX_SIZE][MAX_SIZE], int size_of_map);
int		parse_input(char *arg, int size_of_map, int clues[4][MAX_SIZE]);
int		solve(int grid[MAX_SIZE][MAX_SIZE], int pos, int size_of_map,
			int clues[4][MAX_SIZE]);
void	print_grid(int grid[MAX_SIZE][MAX_SIZE], int size_of_map);

int	main(int argc, char **argv)
{
	int	grid[MAX_SIZE][MAX_SIZE];
	int	clues[4][MAX_SIZE];
	int	size_of_map;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	size_of_map = get_size_from_arg(argv[1]);
	if (size_of_map < 1 || size_of_map > MAX_SIZE)
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_grid(grid, size_of_map);
	if (!parse_input(argv[1], size_of_map, clues)
		|| !solve(grid, 0, size_of_map, clues))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid, size_of_map);
	return (0);
}
