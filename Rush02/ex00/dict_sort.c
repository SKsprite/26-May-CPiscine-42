/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:17 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:19 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	swap_entries(t_entry *a, t_entry *b)
{
	t_entry	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	dict_sort(t_dict *dict)
{
	int	i;
	int	j;

	i = 1;
	while (i < dict->count)
	{
		j = i;
		while (j > 0 && str_cmp_num(dict->entries[j].key,
				dict->entries[j - 1].key) > 0)
		{
			swap_entries(&dict->entries[j], &dict->entries[j - 1]);
			j--;
		}
		i++;
	}
}
