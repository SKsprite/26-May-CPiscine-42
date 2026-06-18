/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:47 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:09:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*step_append_rem(char *prefix, char *r, t_entry *e, t_dict *dict)
{
	char	*r_words;
	char	*result;

	if (r[0] == '0' && !r[1])
		return (prefix);
	r_words = convert_rec(r, dict);
	if (!r_words)
	{
		free(prefix);
		return (NULL);
	}
	result = ft_strjoin3(prefix, get_separator(e->key, r), r_words);
	free(prefix);
	free(r_words);
	return (result);
}

static char	*step_try_key(char *n, t_entry *e, t_dict *dict)
{
	char	q[NUM_BUF_SIZE];
	char	r[NUM_BUF_SIZE];
	char	*q_words;
	char	*prefix;

	if (!e->is_scale || str_cmp_num(e->key, n) > 0)
		return (NULL);
	str_divide(n, e->zeros, q);
	str_remainder(n, e->zeros, r);
	if (str_cmp_num(q, e->key) >= 0)
		return (NULL);
	q_words = convert_rec(q, dict);
	if (!q_words)
		return (NULL);
	prefix = ft_strjoin3(q_words, " ", e->value);
	free(q_words);
	if (!prefix)
		return (NULL);
	return (step_append_rem(prefix, r, e, dict));
}

char	*step_exact_quotient(char *n, t_dict *dict)
{
	char	q[NUM_BUF_SIZE];
	char	r[NUM_BUF_SIZE];
	char	*q_val;
	int		i;

	i = 0;
	while (i < dict->count)
	{
		if (!dict->entries[i].is_scale
			|| count_trailing_zeros(n) < dict->entries[i].zeros)
		{
			i++;
			continue ;
		}
		str_divide(n, dict->entries[i].zeros, q);
		str_remainder(n, dict->entries[i].zeros, r);
		if (r[0] == '0' && !r[1])
		{
			q_val = find_value(q, dict);
			if (q_val)
				return (ft_strjoin3(q_val, " ", dict->entries[i].value));
		}
		i++;
	}
	return (NULL);
}

char	*step_scale_split(char *n, t_dict *dict)
{
	int		i;
	char	*result;

	i = 0;
	while (i < dict->count)
	{
		result = step_try_key(n, &dict->entries[i], dict);
		if (result)
			return (result);
		i++;
	}
	return (NULL);
}

char	*step_additive(char *n, t_dict *dict)
{
	char	b[NUM_BUF_SIZE];
	char	*b_words;
	char	*result;
	int		i;

	i = 0;
	while (i < dict->count)
	{
		if (is_additive_skip(&dict->entries[i], n))
		{
			i++;
			continue ;
		}
		str_subtract(n, dict->entries[i].key, b);
		b_words = convert_rec(b, dict);
		if (b_words)
		{
			result = ft_strjoin3(dict->entries[i].value,
					get_separator(dict->entries[i].key, b), b_words);
			free(b_words);
			return (result);
		}
		i++;
	}
	return (NULL);
}
