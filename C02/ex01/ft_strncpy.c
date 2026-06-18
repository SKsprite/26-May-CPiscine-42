/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:58:03 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/09 14:29:37 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*tmpd;

	tmpd = dest;
	i = 0;
	while (i < n)
	{
		if (*src)
		{
			*tmpd = *src;
			src++;
			tmpd++;
		}
		else
		{
			*tmpd = '\0';
			tmpd++;
		}
		i++;
	}
	return (dest);
}
