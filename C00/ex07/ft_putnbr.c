/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:12:34 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/04 13:35:18 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power(int pos)
{
	int	pow;

	pow = 1;
	while (pos)
	{
		pow *= 10;
		pos--;
	}
	return (pow);
}

void	output_number(int pos, int number)
{
	while (pos >= 0)
	{
		write(1, &(char){'0' + (number / power(pos))}, 1);
		number %= power(pos);
		pos--;
	}
}

void	ft_putnbr(int nb)
{
	int	isneg;
	int	pos;
	int	tmpnb;

	isneg = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		nb = nb * -1;
		write(1, "-", 1);
		isneg++;
	}
	tmpnb = nb;
	pos = 0;
	while (tmpnb / 10 > 0)
	{
		pos++;
		tmpnb /= 10;
	}
	output_number(pos, nb);
}
