/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:02:40 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/14 22:02:42 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	assign_args(int argc, char **argv,
				char **dict_path, char **num_str)
{
	if (argc == 3)
	{
		*dict_path = argv[1];
		*num_str = argv[2];
	}
	else
	{
		*dict_path = DEFAULT_DICT;
		*num_str = argv[1];
	}
}

static void	process(char *num_str, t_dict *dict)
{
	char	*result;

	if (!is_valid_number(num_str))
	{
		ft_putendl("Error");
		return ;
	}
	result = convert_number(num_str, dict);
	if (!result)
		ft_putendl("Dict Error");
	else
	{
		ft_putendl(result);
		free(result);
	}
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*num_str;
	t_dict	*dict;

	if (argc < 2 || argc > 3)
	{
		ft_putendl("Error");
		return (1);
	}
	assign_args(argc, argv, &dict_path, &num_str);
	dict = load_dict(dict_path);
	if (!dict)
	{
		ft_putendl("Dict Error");
		return (1);
	}
	if (ft_strlen(num_str) == 1 && num_str[0] == '-')
		read_stdin_loop(dict);
	else
		process(num_str, dict);
	dict_free(dict);
	return (0);
}
