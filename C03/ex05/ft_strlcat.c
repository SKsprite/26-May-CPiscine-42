/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 08:59:03 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/09 15:41:52 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_i;
	unsigned int	src_i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_i = 0;
	src_i = 0;
	while (dest_i < size && dest[dest_i])
		dest_i++;
	dest_len = dest_i;
	while (src[src_i])
		src_i++;
	src_len = src_i;
	if (dest_len == size)
		return (size + src_len);
	src_i = 0;
	while (src[src_i] && (src_i + dest_len + 1) < size)
	{
		dest[dest_len + src_i] = src[src_i];
		src_i++;
	}
	if (size > 0 && dest_len + src_i < size)
		dest[dest_len + src_i] = '\0';
	return (dest_len + src_len);
}
