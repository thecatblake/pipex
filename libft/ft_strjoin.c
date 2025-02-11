/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:01:44 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/26 17:55:34 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)ft_calloc(len, sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strlcat(s, s1, len);
	ft_strlcat(s, s2, len);
	return (s);
}
