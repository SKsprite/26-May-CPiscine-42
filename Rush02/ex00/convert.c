/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:31 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:08:59 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*skip_leading_zeros(char *s)
{
	while (s[0] == '0' && s[1])
		s++;
	return (s);
}

char	*convert_number(char *n, t_dict *dict)
{
	int	i;

	n = skip_leading_zeros(n);
	if (n[0] == '0' && !n[1])
	{
		i = 0;
		while (i < dict->count)
		{
			if (!dict->entries[i].is_scale
				&& str_cmp_num(dict->entries[i].key, "0") == 0)
				return (ft_strdup(dict->entries[i].value));
			i++;
		}
		return (NULL);
	}
	return (convert_rec(n, dict));
}
