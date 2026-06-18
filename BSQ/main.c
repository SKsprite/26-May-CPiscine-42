/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:48:16 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/16 02:34:26 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	parse_files(int argc, char **argv)
{
	int			i;
	t_checks	dict;

	i = 0;
	while (i++, i < argc)
	{
		init_dict(&dict);
		get_checks_con(argv[i], &dict);
		if (dict.err)
			ft_putendl("Map Error");
		else
			solve(dict);
		if (i + 1 != argc)
			ft_putendl("");
	}
}

void	parse_args(int argc, char **argv)
{
	t_checks	dict;

	if (argc == 1)
	{
		init_dict(&dict);
		read_from_stdin(&dict);
		if (dict.err)
			ft_putendl("Map Error");
		else
			solve(dict);
	}
	else
		parse_files(argc, argv);
}

int	main(int argc, char *argv[])
{
	parse_args(argc, argv);
	return (0);
}
