/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:17 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/26 18:01:50 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_;
	unsigned char	*src_;

	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest_[n] = src_[n];
		}
	}
	return (dest);
}
