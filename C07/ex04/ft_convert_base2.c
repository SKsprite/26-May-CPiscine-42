/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:33:59 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/15 13:09:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *c);

void	str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

char	*malloced(char *word, int neg)
{
	int		length;
	char	*str;

	if (neg > 0)
		return (word);
	length = len(word);
	str = malloc((length + 2) * sizeof(char));
	str[0] = '-';
	str_cpy(str + 1, word);
	free(word);
	return (str);
}

int	base_check(char *str)
{
	int	i;
	int	j;
	int	length;

	length = len(str);
	if (len(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < length)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_base(char *s1, char *s2)
{
	return (base_check(s1) && base_check(s2));
}
