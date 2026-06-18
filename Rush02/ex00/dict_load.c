/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:08 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:10 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*read_file(int fd)
{
	char	buf[1024];
	char	*result;
	char	*tmp;
	int		n;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	n = read(fd, buf, sizeof(buf) - 1);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(result, buf);
		free(result);
		result = tmp;
		if (!result)
			return (NULL);
		n = read(fd, buf, sizeof(buf) - 1);
	}
	if (n < 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static t_dict	*load_fail(char *content, t_dict *dict)
{
	free(content);
	if (dict)
		dict_free(dict);
	return (NULL);
}

t_dict	*load_dict(char *path)
{
	int		fd;
	char	*content;
	t_dict	*dict;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_file(fd);
	close(fd);
	if (!content)
		return (NULL);
	dict = dict_new();
	if (!dict)
		return (load_fail(content, NULL));
	if (parse_content(content, dict) < 0)
		return (load_fail(content, dict));
	free(content);
	dict_sort(dict);
	return (dict);
}
