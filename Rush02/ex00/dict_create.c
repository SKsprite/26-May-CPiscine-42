/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:04 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:04 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dict	*dict_new(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->entries = malloc(sizeof(t_entry) * DICT_INIT_CAP);
	if (!dict->entries)
	{
		free(dict);
		return (NULL);
	}
	dict->count = 0;
	dict->capacity = DICT_INIT_CAP;
	return (dict);
}

int	dict_grow(t_dict *dict)
{
	t_entry	*new_entries;
	int		new_capacity;
	int		i;

	new_capacity = dict->capacity * 2;
	new_entries = malloc(sizeof(t_entry) * new_capacity);
	if (!new_entries)
		return (0);
	i = 0;
	while (i < dict->count)
	{
		new_entries[i] = dict->entries[i];
		i++;
	}
	free(dict->entries);
	dict->entries = new_entries;
	dict->capacity = new_capacity;
	return (1);
}

void	dict_free(t_dict *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (i < dict->count)
	{
		free(dict->entries[i].key);
		free(dict->entries[i].value);
		i++;
	}
	free(dict->entries);
	free(dict);
}
