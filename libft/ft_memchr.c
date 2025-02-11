/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:18:38 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/23 12:06:56 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_;
	unsigned char	c_;
	unsigned int	i;

	s_ = (unsigned char *)s;
	c_ = (unsigned char)c;
	if (n == 0)
		return (NULL);
	i = 0;
	while (s_[i] != c_ && n > 1)
	{
		i++;
		n--;
	}
	if (s_[i] == c_)
		return ((void *)(s_ + i));
	return (NULL);
}
