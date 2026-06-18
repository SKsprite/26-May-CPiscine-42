/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 05:27:50 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 05:34:47 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		a = (unsigned char) s1[i];
		b = (unsigned char) s2[i];
		if (a != b)
			return (a - b);
		i++;
	}
	if (i == n)
		return (0);
	else if (s1[i])
		return ((int) s1[i]);
	else if (s2[i])
		return (-1 * (int) s2[i]);
	return (0);
}
