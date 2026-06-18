/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:02 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:01:05 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	str_cmp_num(char *a, char *b)
{
	int	la;
	int	lb;
	int	i;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la != lb)
		return (la - lb);
	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	if (!a[i])
		return (0);
	return (a[i] - b[i]);
}
