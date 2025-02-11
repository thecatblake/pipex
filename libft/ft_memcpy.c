/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:54:09 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/27 13:57:28 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_;
	char	*src_;

	if (n == 0 && dest != NULL)
		return (dest);
	dest_ = (char *)dest;
	src_ = (char *)src;
	while (n > 0)
	{
		*dest_ = *src_;
		dest_++;
		src_++;
		n--;
	}
	return (dest);
}
