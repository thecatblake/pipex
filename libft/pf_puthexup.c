/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:58:10 by rkaga             #+#    #+#             */
/*   Updated: 2024/11/04 20:58:10 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_digits(unsigned long n, int num)
{
	if (n == 0)
		return (num);
	return (get_digits(n / 16, num + 1));
}

static void	set_digits(unsigned long n, int digits, char *out)
{
	if (digits > 0)
	{
		out[digits - 1] = "0123456789ABCDEF"[n % 16];
		set_digits(n / 16, digits - 1, out);
	}
}

static char	*ft_tohexup(unsigned long n)
{
	int		digits;
	char	*s;

	digits = get_digits(n, 0);
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)ft_calloc(digits + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	set_digits(n, digits, s);
	return (s);
}

int	pf_puthexup(unsigned long d)
{
	char	*s;
	int		len;

	len = 0;
	s = ft_tohexup(d);
	if (s == NULL)
		return (0);
	len += pf_putstr(s);
	free(s);
	return (len);
}
