/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 23:52:01 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/06 00:02:56 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upp(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_alnum(char c)
{
	return (is_low(c) || is_upp(c) || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int		first_found;
	char	*tmp;

	tmp = str;
	first_found = 0;
	while (*str)
	{
		if (!is_alnum(*str))
		{
			first_found = 0;
		}
		else if (!first_found && is_alnum(*str))
		{
			if (is_low(*str))
				*str -= 32;
			first_found = 1;
		}
		else
		{
			if (is_upp(*str))
				*str += 32;
		}
		str++;
	}
	return (tmp);
}
