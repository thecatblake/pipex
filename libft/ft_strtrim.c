/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:06:23 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/23 12:06:56 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	find(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	num;
	char	*last;

	num = 0;
	len = ft_strlen(s1);
	last = (char *)&s1[len - 1];
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (find(*s1, set) && len - num > 0)
	{
		num++;
		s1++;
	}
	while (find(*last--, set) && len - num > 0)
		num++;
	if (len - num <= 0)
		return (ft_strdup(""));
	last = ft_calloc(len - num + 1, sizeof(char));
	if (last == NULL)
		return (NULL);
	ft_memcpy(last, s1, len - num);
	return (last);
}
