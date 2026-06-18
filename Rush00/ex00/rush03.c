/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokkoh, zbhone-m, stkoh <marvin@42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:18:06 by kokkoh, z         #+#    #+#             */
/*   Updated: 2026/05/31 14:18:11 by kokkoh, z        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_border3(int col, int row, int x, int y)
{
	if (col == 1 && (row == 1 || row == y))
		ft_putchar('A');
	else if (col == x && (row == 1 || row == y))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	rush03(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0 || x > 5 || y > 5)
		return ;
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 || col == 1 || row == y || col == x))
				print_border3(col, row, x, y);
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
}
