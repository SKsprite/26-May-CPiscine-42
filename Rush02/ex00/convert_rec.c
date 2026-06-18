/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:37 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:09:05 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*convert_rec(char *n, t_dict *dict)
{
	char	*v;
	char	*result;

	if (n[0] == '0' && !n[1])
		return (ft_strdup(""));
	v = find_value(n, dict);
	if (v)
		return (ft_strdup(v));
	result = step_exact_quotient(n, dict);
	if (result)
		return (result);
	result = step_scale_split(n, dict);
	if (result)
		return (result);
	if (has_scale_key_leq(n, dict))
		return (NULL);
	return (step_additive(n, dict));
}
