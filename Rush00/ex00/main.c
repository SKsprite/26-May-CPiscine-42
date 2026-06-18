/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokkoh, zbhone-m, stkoh <marvin@42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:50:00 by kokkoh, z         #+#    #+#             */
/*   Updated: 2026/05/31 13:50:48 by kokkoh, z        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	void	(*rush)(int, int);

	rush = &rush01;
	if (argc == 2)
	{
		if (argv[1][0] == '0' && argv[1][2] == '\0')
		{
			if (argv[1][1] == '0')
				rush = &rush00;
			else if (argv[1][1] == '2')
				rush = &rush02;
			else if (argv[1][1] == '3')
				rush = &rush03;
			else if (argv[1][1] == '4')
				rush = &rush04;
		}
	}
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	rush(123, 42);
	return (0);
}
