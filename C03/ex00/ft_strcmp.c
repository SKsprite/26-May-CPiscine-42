/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 05:18:50 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 05:26:54 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 && *s2)
	{
		a = (unsigned char) *s1;
		b = (unsigned char) *s2;
		if (a != b)
		{
			return (a - b);
		}
		s1++;
		s2++;
	}
	if (*s1)
		return ((int) *s1);
	else if (*s2)
		return (-1 * (int) *s2);
	return (0);
}
