/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:03:04 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:03:05 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		l1;
	int		l2;
	int		i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc(l1 + l2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		result[i] = s2[i - l1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, s3);
	free(tmp);
	return (result);
}
