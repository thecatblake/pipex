/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:49 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/28 14:40:59 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n, int num)
{
	if (n == 0)
		return (num);
	return (get_digits(n / 10, num + 1));
}

static void	set_digits(long n, int digits, char *out)
{
	if (digits > 0)
	{
		out[digits - 1] = n % 10 + '0';
		set_digits(n / 10, digits - 1, out);
	}
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*s;

	digits = get_digits(n, 0);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		s = (char *)ft_calloc(digits + 2, sizeof(char));
		if (s == NULL)
			return (NULL);
		s[0] = '-';
		set_digits(n * -1, digits, s + 1);
	}
	else
	{
		s = (char *)ft_calloc(digits + 1, sizeof(char));
		if (s == NULL)
			return (NULL);
		set_digits(n, digits, s);
	}
	return (s);
}
