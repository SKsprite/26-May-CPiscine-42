/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:51 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:01:53 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*find_value(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		if (!dict->entries[i].is_scale
			&& str_cmp_num(dict->entries[i].key, key) == 0)
			return (dict->entries[i].value);
		i++;
	}
	return (NULL);
}

char	*get_separator(char *key, char *rem)
{
	if (str_cmp_num(key, "1000") >= 0)
	{
		if (str_cmp_num(rem, "100") < 0)
			return (" and ");
		return (", ");
	}
	if (str_cmp_num(key, "100") == 0)
		return (" and ");
	return ("-");
}

int	has_scale_key_leq(char *n, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		if (dict->entries[i].is_scale
			&& str_cmp_num(dict->entries[i].key, n) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_additive_skip(t_entry *e, char *n)
{
	return (e->is_scale || e->key[0] == '0'
		|| str_cmp_num(e->key, n) >= 0);
}
