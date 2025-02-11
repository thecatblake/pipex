/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:42:26 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/12 03:42:26 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft/libft.h"

char	*get_path_env(char **environ)
{
	while (*environ)
	{
		if (ft_strncmp(*environ, "PATH", 4) == 0)
			return (*environ);
		environ++;
	}
	return (NULL);
}
