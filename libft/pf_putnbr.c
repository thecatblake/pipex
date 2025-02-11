/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:57:58 by rkaga             #+#    #+#             */
/*   Updated: 2024/11/04 20:57:58 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putnbr(long d)
{
	char	*s;
	int		len;

	len = 0;
	s = ft_itoa(d);
	if (s == NULL)
		return (0);
	len += pf_putstr(s);
	free(s);
	return (len);
}
