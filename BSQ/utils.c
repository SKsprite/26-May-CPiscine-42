/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 23:19:20 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 02:52:11 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bool	isnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	f_atoi(char *str)
{
	int	num;
	int	digit;

	num = 0;
	while (*str)
	{
		digit = *str - '0';
		if (num > (2147483647 - digit) / 10)
			return (-1);
		num = num * 10 + digit;
		str++;
	}
	return (num);
}

void	init_dict(t_checks *dict)
{
	dict->emp = '\0';
	dict->sqa = '\0';
	dict->obs = '\0';
	dict->err = 0;
	dict->cols = 0;
	dict->rows = 0;
	dict->max = 0;
	dict->map = NULL;
	dict->buf_pos = 0;
	dict->buf_len = 0;
}
