/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:37:51 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 04:15:14 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_checks	*fill_dict(int fd, t_checks *dict)
{
	int	**tmp;
	int	i;

	parse_header(fd, dict);
	if (dict->err)
		return (dict);
	tmp = malloc(sizeof(int *) * (dict->rows + 1));
	if (!tmp)
		return (dict->err = ERR_MALLOC, dict);
	i = 0;
	while (i <= dict->rows)
		tmp[i++] = NULL;
	dict->map = tmp;
	if (fill_map(fd, dict))
	{
		free_map(dict->map);
		dict->map = NULL;
	}
	return (dict);
}

t_checks	get_checks_con(char *filename, t_checks *dict)
{
	int	file_fd;

	file_fd = open(filename, O_RDONLY);
	dict = fill_dict(file_fd, dict);
	close(file_fd);
	return (*dict);
}

t_checks	read_from_stdin(t_checks *dict)
{
	dict = fill_dict(STDIN, dict);
	return (*dict);
}

void	solve(t_checks dict)
{
	dict.map = biggest_sq(dict.map, dict.rows, dict.cols, &dict.max);
	normalize_map(dict);
	print_map(dict);
}
