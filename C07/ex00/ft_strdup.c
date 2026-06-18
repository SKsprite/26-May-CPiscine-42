/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:28:40 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 15:55:35 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(len(src) * sizeof(char));
	while (i <= len(src))
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}
