/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 05:49:55 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/09 15:53:25 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ret_dest;
	unsigned int	br;

	br = 0;
	ret_dest = dest;
	while (*dest)
		dest++;
	while (src[br] && br < nb)
	{
		*dest = src[br];
		dest++;
		br++;
	}
	*dest = '\0';
	return (ret_dest);
}
