/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 00:39:35 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 04:55:44 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

const char	*g_hex = "0123456789abcdef";

unsigned long	hex_ex(int count)
{
	if (count <= 0)
		return (1);
	return (16 * hex_ex(count - 1));
}

void	print_hex(unsigned char *addr, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < count)
		{
			write(1, &(char){g_hex[addr[i] / 16]}, 1);
			write(1, &(char){g_hex[addr[i] % 16]}, 1);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_addr(unsigned long addr)
{
	int				place[16];
	int				i;

	i = 16;
	while (i > 0)
	{
		place[16 - i] = addr / hex_ex(i - 1);
		if (i > 1)
			addr %= hex_ex(i - 1);
		i--;
	}
	while (i < 16)
	{
		write(1, &(char){g_hex[place[i]]}, 1);
		i++;
	}
	write(1, ": ", 2);
}

void	print_str(unsigned char *addr, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, &(char){addr[i]}, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*ptr;
	unsigned long	address;
	unsigned int	chunk;

	ptr = addr;
	while (size > 0)
	{
		if (size >= 16)
			chunk = 16;
		else
			chunk = size;
		address = (unsigned long) addr;
		print_addr(address);
		print_hex(addr, chunk);
		print_str(addr, chunk);
		size -= chunk;
		addr += chunk;
	}
	return (ptr);
}
