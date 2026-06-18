/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:50:16 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 00:41:51 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &(char){'0' + arr[i]}, 1);
		i++;
	}
}

int	sum_arr(int *arr, int n)
{
	int	result;

	result = 0;
	while (n > 0)
	{
		result += arr[n - 1];
		n--;
	}
	return (result);
}

void	reccur(int digit, int pos, int n, int *arr)
{
	if (pos >= n)
		return ;
	while (digit < 10 + pos - n + 1)
	{
		arr[pos] = digit;
		if (pos + 1 == n)
		{
			print(arr, n);
			if (sum_arr(arr, n) != (n * (19 - n)) / 2)
				write(1, ", ", 2);
		}
		else
			reccur(digit + 1, pos + 1, n, arr);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	reccur(0, 0, n, arr);
}
