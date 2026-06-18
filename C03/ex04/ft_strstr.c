/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 05:54:53 by stkoh             #+#    #+#             */
/*   Updated: 2026/06/11 01:19:30 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*needle;
	char	*fur_look;
	int		found;
	int		length;

	length = len(to_find);
	if (!length)
		return (str);
	while (*str)
	{
		found = 0;
		needle = to_find;
		fur_look = str;
		while (needle[found] && fur_look[found]
			&& fur_look[found] == needle[found])
		{
			found++;
		}
		if (found == length)
			return (str);
		str++;
	}
	return (0);
}
