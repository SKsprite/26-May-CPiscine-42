/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_trim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:24 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:25 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*trim(char *s)
{
	int		start;
	int		end;
	int		len;
	char	*result;
	int		i;

	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\r')
		start++;
	end = ft_strlen(s) - 1;
	while (end >= start && (s[end] == ' ' || s[end] == '\t'
			|| s[end] == '\r'))
		end--;
	len = end - start + 1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
