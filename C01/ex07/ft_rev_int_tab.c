/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:03:32 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/03 15:10:03 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	swp;
	int	*bptr;

	if (!tab || size <= 0)
		return ;
	bptr = &tab[size - 1];
	while (tab < bptr)
	{
		swp = *tab;
		*tab = *bptr;
		*bptr = swp;
		bptr--;
		tab++;
	}
}
