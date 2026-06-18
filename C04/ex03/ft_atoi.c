/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:52:15 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/10 14:56:55 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	min_count;

	i = 0;
	min_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min_count++;
		i++;
	}
	count = get_atoi(&str[i]);
	if (min_count % 2)
		count *= -1;
	return (count);
}
