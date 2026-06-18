/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:37:51 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 04:15:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	buf_read_char(int fd, t_checks *dict)
{
	if (dict->buf_pos >= dict->buf_len)
	{
		dict->buf_len = read(fd, dict->buf, BUFF_SIZE);
		dict->buf_pos = 0;
	}
	if (dict->buf_len <= 0)
		return ('\0');
	return (dict->buf[dict->buf_pos++]);
}

void	shift_chars(char c, t_checks *dict)
{
	if (dict->obs)
		dict->emp = dict->obs;
	if (dict->sqa)
		dict->obs = dict->sqa;
	dict->sqa = c;
}

char	*read_header_line(int fd, t_checks *dict)
{
	char	*num;
	char	*tmp;
	char	c;

	num = malloc(1);
	if (!num)
		return (dict->err = ERR_MALLOC, NULL);
	num[0] = '\0';
	c = buf_read_char(fd, dict);
	while (c && line_not_end(c))
	{
		shift_chars(c, dict);
		tmp = str_join(num, c);
		if (!tmp)
			return (free(num), dict->err = ERR_MALLOC, NULL);
		free(num);
		num = tmp;
		c = buf_read_char(fd, dict);
	}
	return (num);
}

void	parse_header(int fd, t_checks *dict)
{
	char	*num;

	num = read_header_line(fd, dict);
	if (!num)
		return ;
	if (length(num) <= 3)
	{
		free(num);
		dict->err = ERR_MAP_INFO;
		return ;
	}
	if (parse_num(num, dict))
	{
		free(num);
		return ;
	}
	free(num);
	if (!valid_chars(dict))
		dict->err = ERR_MAP_INFO;
}

char	*read_line_valid(int fd, t_checks *dict)
{
	char	*num;
	char	*tmp;
	char	c;

	num = malloc(1);
	if (!num)
		return (dict->err = ERR_MALLOC, NULL);
	num[0] = '\0';
	c = buf_read_char(fd, dict);
	while (c && line_not_end(c))
	{
		if (c != dict->emp && c != dict->obs)
			return (free(num), dict->err = ERR_MAP_CHAR, NULL);
		tmp = str_join(num, c);
		if (!tmp)
			return (free(num), dict->err = ERR_MALLOC, NULL);
		free(num);
		num = tmp;
		c = buf_read_char(fd, dict);
	}
	return (num);
}
