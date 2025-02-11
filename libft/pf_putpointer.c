/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:57:53 by rkaga             #+#    #+#             */
/*   Updated: 2024/11/04 20:57:53 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putpointer(void *p)
{
	unsigned long	ptr;
	int				len;

	if (p == NULL)
	{
		len = write(1, "(nil)", 5);
	}
	else
	{
		ptr = (unsigned long)p;
		len = write(1, "0x", 2);
		len += pf_puthexlow(ptr);
	}
	return (len);
}
