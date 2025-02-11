/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:51:04 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/23 20:51:04 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = 0;
	while (*s)
	{
		if (*s == (char)c)
			found = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (found);
}
