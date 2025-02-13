/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:07:44 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/05 01:27:55 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    int byte_read = read(STDIN_FILENO, s, 10000);
    printf("%d", byte_read);
    return 0;
}