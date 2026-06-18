/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:59:59 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/15 15:04:25 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	valid_chars(t_checks *dict)
{
	if (dict->emp == dict->obs || dict->emp == dict->sqa)
		return (0);
	if (dict->obs == dict->sqa)
		return (0);
	if (dict->emp < ' ' || dict->emp > '~')
		return (0);
	if (dict->obs < ' ' || dict->obs > '~')
		return (0);
	if (dict->sqa < ' ' || dict->sqa > '~')
		return (0);
	return (1);
}

int	parse_num(char *num, t_checks *dict)
{
	int	len;

	len = length(num) - 3;
	num[len] = '\0';
	if (!isnum(num))
		return (dict->err = ERR_INV_NUM);
	dict->rows = f_atoi(num);
	if (dict->rows == -1)
		return (dict->err = ERR_INV_NUM);
	if (dict->rows == 0)
		return (dict->err = ERR_MAP_INFO);
	return (0);
}
