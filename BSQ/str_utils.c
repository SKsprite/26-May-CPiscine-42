/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:24:23 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 00:31:44 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	arrcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*f_realloc(char *ptr, int size)
{
	char	*array;

	array = malloc(size * sizeof(char));
	if (!array)
		return (NULL);
	arrcpy(array, ptr);
	return (array);
}

char	*str_join(char *str1, char c)
{
	char	*tmp;
	int		count;

	tmp = f_realloc(str1, (length(str1) + 2));
	if (!tmp)
		return (NULL);
	count = 0;
	while (str1[count])
		count++;
	tmp[count] = c;
	tmp[count + 1] = '\0';
	return (tmp);
}
