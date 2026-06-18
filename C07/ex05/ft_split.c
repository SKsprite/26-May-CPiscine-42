/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:00:41 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/18 16:35:56 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	in_set(char *charset, char c)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!in_set(charset, *str))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}

static int	get_wlen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !in_set(charset, str[len]))
		len++;
	return (len);
}

static char	*get_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = get_wlen(str, charset);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!in_set(charset, *str))
		{
			arr[i] = get_word(str, charset);
			while (*str && !in_set(charset, *str))
				str++;
			i++;
		}
		else
			str++;
	}
	arr[i] = NULL;
	return (arr);
}
