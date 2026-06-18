/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:43:39 by stkoh             #+#    #+#             */
/*   Updated: 2026/05/29 14:58:28 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[9];
	int	*tab;
	int	i;

	i = 0;
	arr[0] = 5;
	arr[1] = 4;
	arr[2] = 7;
	arr[3] = 6;
	arr[4] = 2;
	arr[5] = 1;
	arr[6] = 9;
	arr[7] = 8;
	arr[8] = 3;
	tab = arr;
	ft_sort_int_tab(tab, 9);
	while (i < 9)
	{
		printf("%d", arr[i]);
		i++;
	}
}
