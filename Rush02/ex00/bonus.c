/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:01:24 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:08:48 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	process_line(char *buf, int *pos, t_dict *dict)
{
	char	*result;

	buf[*pos] = '\0';
	if (!is_valid_number(buf))
		ft_putendl("Error");
	else
	{
		result = convert_number(buf, dict);
		if (!result)
			ft_putendl("Dict Error");
		else
		{
			ft_putendl(result);
			free(result);
		}
	}
	*pos = 0;
}

void	read_stdin_loop(t_dict *dict)
{
	char	buf[NUM_BUF_SIZE];
	int		pos;
	char	c;
	int		n;

	pos = 0;
	n = read(0, &c, 1);
	while (n > 0)
	{
		if (c == '\n')
			process_line(buf, &pos, dict);
		else if (pos < NUM_BUF_SIZE - 2)
		{
			buf[pos] = c;
			pos++;
		}
		n = read(0, &c, 1);
	}
}
