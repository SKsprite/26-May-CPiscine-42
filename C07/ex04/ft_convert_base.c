/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:50:23 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/15 13:14:10 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	str_cpy(char *s1, char *s2);
char	*malloced(char *s1, int neg);
int		valid_base(char *base_to, char *base_from);

int	len(char *c)
{
	int	count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}

int	san_num(char nbr)
{
	return ((nbr >= 9 && nbr <= 13) || nbr == '-'
		|| nbr == '+' || nbr == ' ');
}

int	atoi_base(char *nbr, char *base_from, int length)
{
	int	return_value;
	int	i;
	int	set;

	return_value = 0;
	while (*nbr)
	{
		i = 0;
		set = 0;
		while (i < length)
		{
			if (*nbr == base_from[i])
			{
				return_value *= length;
				return_value += i;
				set = 1;
			}
			i++;
		}
		if (!set)
			return (return_value);
		nbr++;
	}
	return (return_value);
}

char	*itoa_base(int num, char *base, int length)
{
	char	*arr;
	char	*str;

	if (num < length)
	{
		arr = malloc(2);
		arr[0] = base[num];
		arr[1] = '\0';
		return (arr);
	}
	str = itoa_base(num / length, base, length);
	arr = malloc(len(str) + 2);
	str_cpy(arr, str);
	arr[len(str)] = base[num % length];
	arr[len(str) + 1] = '\0';
	free(str);
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		neg;
	char	*based;

	if (!valid_base(base_to, base_from))
		return (NULL);
	neg = 1;
	while (san_num(*nbr))
	{
		if (*nbr == '-')
			neg *= -1;
		nbr++;
	}
	num = atoi_base(nbr, base_from, len(base_from));
	based = malloc((1) * sizeof(char));
	if (!based)
		return ((void *) 0);
	free(based);
	based = itoa_base(num, base_to, len(base_to));
	based = malloced(based, neg);
	return (based);
}
