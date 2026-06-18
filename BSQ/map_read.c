/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:37:51 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 04:15:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_from_str(char *num, int *row, t_checks dict)
{
	int	i;

	i = 0;
	while (i < dict.cols)
	{
		row[i] = (num[i] != dict.obs);
		i++;
	}
	row[i] = 0;
}

int	alloc_row_block(t_checks *dict)
{
	int	*data;
	int	i;

	data = malloc(sizeof(int) * dict->rows * (dict->cols + 1));
	if (!data)
		return (dict->err = ERR_MALLOC);
	i = 0;
	while (i < dict->rows)
	{
		dict->map[i] = data + i * (dict->cols + 1);
		i++;
	}
	dict->map[i] = NULL;
	return (0);
}

int	fill_first_row(int fd, t_checks *dict)
{
	char	*num;

	num = read_line_valid(fd, dict);
	if (!num)
		return (dict->err);
	dict->cols = length(num);
	if (dict->cols == 0)
		return (free(num), dict->err = ERR_MAP_INFO);
	if (alloc_row_block(dict))
		return (free(num), dict->err);
	fill_from_str(num, dict->map[0], *dict);
	free(num);
	return (0);
}

int	read_row_direct(int fd, t_checks *dict, int idx)
{
	int		i;
	char	c;

	i = 0;
	while (i < dict->cols)
	{
		c = buf_read_char(fd, dict);
		if (c != dict->emp && c != dict->obs)
			return (dict->err = ERR_MAP_CHAR);
		dict->map[idx][i++] = (c != dict->obs);
	}
	dict->map[idx][i] = 0;
	c = buf_read_char(fd, dict);
	if (c && c != '\n')
		return (dict->err = ERR_MAP_COL);
	return (0);
}

int	fill_map(int fd, t_checks *dict)
{
	int		i;
	char	c;

	if (fill_first_row(fd, dict))
		return (dict->err);
	i = 1;
	while (i < dict->rows)
	{
		if (read_row_direct(fd, dict, i))
			return (dict->err);
		i++;
	}
	c = buf_read_char(fd, dict);
	if (c)
		return (dict->err = ERR_MAP_INFO);
	return (0);
}
