/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:03:25 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:03:27 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_trailing_zeros(char *s)
{
	int	len;
	int	count;

	len = ft_strlen(s);
	count = 0;
	while (len > 0 && s[len - 1] == '0')
	{
		count++;
		len--;
	}
	return (count);
}
