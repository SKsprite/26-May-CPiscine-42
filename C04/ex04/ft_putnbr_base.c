/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:18:24 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/10 14:58:28 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_len(char *base)
{
	int	count;

	count = 0;
	while (base[count])
		count++;
	return (count);
}

int	check_base_unique(char *base, int len)
{
	int	ptr;
	int	sptr;

	ptr = 0;
	while (ptr < len)
	{
		sptr = ptr + 1;
		while (base[sptr])
		{
			if (base[ptr] == base[sptr])
				return (0);
			sptr++;
		}
		ptr++;
	}
	return (1);
}

int	base_is_valid(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

void	print_nbr(long nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	print_nbr(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_system;
	long	longnbr;

	base_system = base_len(base);
	longnbr = (long) nbr;
	if (base_system <= 1 || !check_base_unique(base, base_system)
		|| !base_is_valid(base))
		return ;
	if (longnbr < 0)
	{
		write(1, "-", 1);
		longnbr *= -1;
	}
	if (longnbr == 0)
		write(1, &base[0], 1);
	print_nbr((long) longnbr, base, base_system);
}
