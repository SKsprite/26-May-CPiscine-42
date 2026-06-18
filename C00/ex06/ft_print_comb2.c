/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:16:35 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/03 14:43:50 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(int a)
{
	write(1, &a, 1);
}

void	print_comb(int a, int b)
{
	print_char((a / 10) + '0');
	print_char((a % 10) + '0');
	print_char(' ');
	print_char((b / 10) + '0');
	print_char((b % 10) + '0');
	if (!(b == 99 && a == 98))
	{
		print_char(',');
		print_char(' ');
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a < 100)
	{
		b = a;
		while (b < 100)
		{
			if (a != b)
			{
				print_comb(a, b);
			}
			b++;
		}
		a++;
	}
}
