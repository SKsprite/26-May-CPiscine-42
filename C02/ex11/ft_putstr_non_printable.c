/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 00:16:50 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 13:52:22 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_c(char c)
{
	write(1, &c, 1);
}

int	is_non(char c)
{
	return (c < 32 || c > 126);
}

void	put_non_c(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	put_c('\\');
	put_c(hex[c / 16]);
	put_c(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_non(*str))
			put_non_c(*str);
		else
			put_c(*str);
		str++;
	}
}
