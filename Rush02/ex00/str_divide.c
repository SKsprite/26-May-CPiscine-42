/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_divide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:57 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:08:33 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	str_divide(char *n, int z, char *out)
{
	int	len;
	int	result_len;
	int	start;
	int	i;

	len = ft_strlen(n);
	if (len <= z)
	{
		out[0] = '0';
		out[1] = '\0';
		return ;
	}
	result_len = len - z;
	start = 0;
	while (start < result_len - 1 && n[start] == '0')
		start++;
	i = 0;
	while (start + i < result_len)
	{
		out[i] = n[start + i];
		i++;
	}
	out[i] = '\0';
}
