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
    char *path = "/usr/bin/ls";
    char *args[] = {path, "-l", NULL};
	execve(args[0], args, environ);
    write(1, "ok", 2);
	return (0);
}