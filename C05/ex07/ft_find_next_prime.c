/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 06:26:28 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 08:18:33 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int n)
{
	int	i;
	int	half;

	if (n <= 1)
		return (0);
	half = n / 2;
	i = 2;
	while (i <= half)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (is_prime(nb))
	{
		return (nb);
	}
	return (ft_find_next_prime(nb + 1));
}
