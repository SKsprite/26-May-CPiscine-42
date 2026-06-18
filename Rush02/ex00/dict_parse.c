/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:12 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:13 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	parse_fail(char *key, char *value)
{
	free(key);
	free(value);
	return (-1);
}

static t_entry	make_entry(char *key, char *value)
{
	t_entry	entry;

	entry.key = key;
	entry.value = value;
	entry.is_scale = is_scale_key(key, &entry.zeros);
	if (!entry.is_scale)
		entry.zeros = 0;
	return (entry);
}

int	parse_line(char *line, t_dict *dict)
{
	int		colon;
	char	*key;
	char	*value;

	colon = 0;
	while (line[colon] && line[colon] != ':')
		colon++;
	if (!line[colon])
		return (-1);
	line[colon] = '\0';
	key = trim(line);
	value = trim(line + colon + 1);
	line[colon] = ':';
	if (!key || !value || !is_valid_number(key))
		return (parse_fail(key, value));
	if (dict->count >= dict->capacity && !dict_grow(dict))
		return (parse_fail(key, value));
	dict->entries[dict->count] = make_entry(key, value);
	dict->count++;
	return (0);
}

int	parse_content(char *content, t_dict *dict)
{
	int		i;
	int		start;
	char	save;

	i = 0;
	while (content[i])
	{
		start = i;
		while (content[i] && content[i] != '\n')
			i++;
		save = content[i];
		content[i] = '\0';
		if (content[start] != '\0' && content[start] != '#')
		{
			if (parse_line(content + start, dict) < 0)
			{
				content[i] = save;
				return (-1);
			}
		}
		content[i] = save;
		if (content[i])
			i++;
	}
	return (0);
}
