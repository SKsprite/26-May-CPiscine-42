/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remainder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:03:13 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:03:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	str_remainder(char *n, int z, char *out)
{
	int	len;
	int	start;
	int	i;

	len = ft_strlen(n);
	if (len <= z)
		start = 0;
	else
		start = len - z;
	while (start < len - 1 && n[start] == '0')
		start++;
	i = 0;
	while (n[start + i])
	{
		out[i] = n[start + i];
		i++;
	}
	out[i] = '\0';
}
