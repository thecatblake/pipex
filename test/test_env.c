/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:38:54 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/12 03:42:05 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

extern char	**environ;

int main(void) {
    while (*environ) {
        if (ft_strncmp(*environ, "PATH", 4) == 0)
            printf("%s\n", *environ);
        environ++;
    }
    return (0);
}