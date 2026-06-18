/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:06:11 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 03:59:08 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		count++;
	}
	return (count);
}

int	check_base_valid(char *base, int len)
{
	int	bptr;
	int	ptr;
	char	c;

	ptr = 0;
	if (len <= 1)
		return (0);
	while (base[ptr])
	{
		c = base[ptr];
		bptr = ptr + 1;
		if (c == '+' || c == '-' || c == ' ' || (c >= 9 && c <= 13))
			return (0);
		while (base[bptr])
		{
			if (base[bptr] == base[ptr])
				return (0);
			bptr++;
		}
		ptr++;
	}
	return (1);
}

int	ft_atoi(char *str, char *base, int len)
{
	int	i;
	int	num;

	num = 0;
	if (!*str)
		return (0);
	while(*str)
	{
		i = 0;
		while (base[i])
		{
			if (*str == base[i])
			{
				num *= len;
				num += i;
				break ;
			}
			i++;
		}
		if (i == len)
			return (num);
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ret_val;
	int	neg_c;
	int	len_base;

	len_base = len(base);
	neg_c = 0;
	if (!check_base_valid(base, len_base))
		return (0);
	while (*str == '+' || *str == '-' || *str == ' ' || (*str >= 9 && *str <= 13))
	{
		if	(*str == '-')
			neg_c++;
		str++;
	}
	ret_val = ft_atoi(str, base, len_base);
	if (neg_c % 2)
		ret_val *= -1;
	return (ret_val);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[] = "01";

	printf("%d", ft_atoi_base("         ---10101001", str));
}
*/
