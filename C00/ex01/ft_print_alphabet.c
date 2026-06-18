/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:24:15 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/04 13:19:49 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	*start;

	start = "abcdefghijklmnopqrstuvwxyz";
	while (*start)
	{
		write(1, start++, 1);
	}
}
