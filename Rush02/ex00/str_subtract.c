/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:03:18 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:03:20 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	strip_leading_zeros(char *result, char *out)
{
	int	start;
	int	m;

	start = 0;
	while (result[start] == '0' && result[start + 1])
		start++;
	m = 0;
	while (result[start + m])
	{
		out[m] = result[start + m];
		m++;
	}
	out[m] = '\0';
}

static int	subtract_digit(int d_n, int d_s, int *borrow)
{
	int	diff;

	diff = d_n - d_s - *borrow;
	if (diff < 0)
	{
		diff += 10;
		*borrow = 1;
	}
	else
		*borrow = 0;
	return (diff);
}

static void	subtract_loop(char *n, char *sub, char *res)
{
	int	borrow;
	int	i;
	int	j;
	int	len;
	int	d_s;

	borrow = 0;
	len = ft_strlen(n);
	i = len - 1;
	j = ft_strlen(sub) - 1;
	while (i >= 0)
	{
		d_s = 0;
		if (j >= 0)
			d_s = sub[j] - '0';
		res[i] = '0' + subtract_digit(n[i] - '0', d_s, &borrow);
		i--;
		j--;
	}
	res[len] = '\0';
}

void	str_subtract(char *n, char *sub, char *out)
{
	char	result[NUM_BUF_SIZE];

	subtract_loop(n, sub, result);
	strip_leading_zeros(result, out);
}
