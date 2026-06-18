/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:24:33 by stkoh             #+#    #+#             */
/*   Updated: 2026/05/29 15:35:38 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* This is a test file for CPiscineC01
*
* Run:
* norminette -R CheckForbiddenSourceHeader
* [file.c / folder]
*
* Compile with:
* cc -Wall -Werror -Wextra
* main.c
* ../CPiscineC01/ex00/ft_ft.c
* ../CPiscineC01/ex01/ft_ultimate_ft.c
* ../CPiscineC01/ex02/ft_swap.c
* ../CPiscineC01/ex03/ft_div_mod.c
* ../CPiscineC01/ex04/ft_ultimate_div_mod.c
* ../CPiscineC01/ex05/ft_putstr.c
* ../CPiscineC01/ex06/ft_strlen.c
* ../CPiscineC01/ex07/ft_rev_int_tab.c
* ../CPiscineC01/ex08/ft_sort_int_tab_.c
*
*/

#include <stdio.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	return (0);
}

void	test_void(void)
{
	printf("\nTesting void\n");
}
