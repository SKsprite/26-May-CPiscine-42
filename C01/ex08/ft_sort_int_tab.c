/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:16:59 by stkoh             #+#    #+#             */
/*   Updated: 2026/05/29 15:01:42 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
 *	{0,1,2,3,4,5,...}
 *	SIZE =10
 *	0 - 9
 *
 *	int
 *
 *	[5,4,2,6,1,9]
 *
 *	[5,4,2,6,1,9]
 *	[4,5,2]
 */

void	ft_sort_int_tab(int *tab, int size)
{
	int	curr;
	int	check;
	int	swp;

	curr = 0;
	check = 0;
	while (curr < size)
	{
		check = curr + 1;
		while (check < size)
		{
			if (tab[check] < tab[curr])
			{
				swp = tab[curr];
				tab[curr] = tab[check];
				tab[check] = swp;
			}
			check++;
		}
		curr++;
	}
}
