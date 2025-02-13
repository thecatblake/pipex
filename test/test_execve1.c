/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:29:36 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:13:48 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

int	main(int argc, char **argv)
{
    char *path = "exit";
    char *args[] = {path, "5", NULL};
	int result = execve(args[0], args, environ);
    printf("%d\n", result);
	return (0);
}