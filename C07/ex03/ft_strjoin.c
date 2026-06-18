/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:57:25 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/15 11:08:24 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

int	ft_mal_size(int size, char **strs, char *sep)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += len(strs[i++]);
	}
	return (length + (len(sep) * (size - 1)));
}

char	*assign(int size, char **strs, char *sep)
{
	char	*word;
	char	*str;
	int		pos;
	int		i;

	i = 0;
	word = malloc(ft_mal_size(size, strs, sep) * sizeof(char));
	if (!word)
		return (0);
	pos = 0;
	while (i < size)
	{
		str = strs[i];
		while (*str)
			word[pos++] = *str++;
		if (i < size - 1)
		{
			str = sep;
			while (*str)
				word[pos++] = *str++;
		}
		i++;
	}
	word[pos] = '\0';
	return (word);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*word;

	if (size == 0)
	{
		word = malloc(sizeof(char) * 1);
		if (!word)
			return (NULL);
		word[0] = '\0';
		return (word);
	}
	return (assign(size, strs, sep));
}
