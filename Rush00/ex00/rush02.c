/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokkoh, zbhone-m, stkoh <marvin@42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:45 by kokkoh, z         #+#    #+#             */
/*   Updated: 2026/05/31 14:12:48 by kokkoh, z        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_border2(int col, int row, int x, int y)
{
	if (row == 1 && (col == 1 || col == x))
		ft_putchar('A');
	else if (row == y && (col == 1 || col == x))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	rush02(int x, int y)
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
				print_border2(col, row, x, y);
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
}
