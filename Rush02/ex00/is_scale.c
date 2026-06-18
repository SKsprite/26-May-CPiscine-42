/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:34 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:37 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_scale_key(char *key, int *zeros)
{
	int	len;
	int	i;

	len = ft_strlen(key);
	if (len < 3 || key[0] != '1')
		return (0);
	i = 1;
	while (key[i])
	{
		if (key[i] != '0')
			return (0);
		i++;
	}
	if (zeros)
		*zeros = len - 1;
	return (1);
}
