/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:37:16 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/23 12:06:56 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	k;
	size_t	llen;

	llen = ft_strlen(little);
	if (big == NULL && len == 0)
		return (NULL);
	if (llen == 0)
		return ((char *)big);
	while (*big && len > 0)
	{
		k = 0;
		while (len - k > 0 && k < llen && *(big + k) == little[k])
			k++;
		if (k == llen)
			return ((char *)(big));
		big++;
		len--;
	}
	return (0);
}
