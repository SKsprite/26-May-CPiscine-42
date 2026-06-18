/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:38:47 by stkoh             #+#    #+#             */
/*   Updated: 2026/05/29 16:05:48 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a test file for CPiscineC00
**
** Run:
** norminette -R CheckForbiddenSourceHeader
** [file.c / folder]
**
** Compile with:
** cc -Wall -Werror -Wextra
** main.c
** ../CPiscineC00/ex00/ft_putchar.c
** ../CPiscineC00/ex01/ft_print_alphabet.c
** ../CPiscineC00/ex02/ft_print_numbers.c
** ../CPiscineC00/ex03/ft_print_.c
*/

#include <stdio.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);

void	test_putchar(void)
{
	printf("Testing ft_putchar.c\n");
	ft_putchar('a');
	printf("\n");
	printf("\n");
}

void	test_print_alphabet(void)
{
	printf("\nTesting ft_print_alphabet.c\n");
	ft_print_alphabet();
	printf("\n");
	printf("\n");
}

void	test_print_reverse_alphabet(void)
{
	printf("\nTesting ft_print_reverse_alphabet.c\n");
	ft_print_reverse_alphabet();
	printf("\n");
	printf("\n");
}

void	test_print_numbers(void)
{
	printf("\nTesting ft_print_numbers.c\n");
	ft_print_numbers();
	printf("\n");
	printf("\n");
}

void	test_is_negative(void)
{
	printf("\nTesting ft_is_negative.c\n");
	ft_is_negative(-2);
	ft_is_negative(-100);
	ft_is_negative(0);
	ft_is_negative(15);
	ft_is_negative(12);
	ft_is_negative(-21);
	printf("\n");
	printf("\n");
}

void	test_print_comb(void)
{
	printf("\nTesting ft_print_comb.c\n");
	ft_print_comb();
	printf("\n");
	printf("\n");
}

int	main(void)
{
	test_putchar();
	test_print_alphabet();
	test_print_reverse_alphabet();
	test_print_numbers();
	test_is_negative();
	test_print_comb();
	printf("\nEnd of test\n");
	return (0);
}


