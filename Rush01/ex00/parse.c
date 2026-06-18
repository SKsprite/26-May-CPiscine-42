/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:33:44 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/07 15:21:08 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_SIZE 9

int	parse_input(char *arg, int size_of_map, int clues[4][MAX_SIZE])
{
	int	i;
	int	arg_i;
	int	total;

	i = 0;
	arg_i = 0;
	total = size_of_map * 4;
	while (i < total)
	{
		if (arg[arg_i] < '1' || arg[arg_i] > '0' + size_of_map)
			return (0);
		clues[i / size_of_map][i % size_of_map] = arg[arg_i] - '0';
		arg_i++;
		if (i < total - 1)
		{
			if (arg[arg_i] != ' ')
				return (0);
			arg_i++;
		}
		i++;
	}
	if (arg[arg_i] != '\0')
		return (0);
	return (1);
}

int	get_size_from_arg(char *arg)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			count++;
		i++;
	}
	return ((count + 1) / 4);
}
