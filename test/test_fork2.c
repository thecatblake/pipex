/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:26:29 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:02 by rkaga            ###   ########.fr       */
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
	int fields[2];
	int buf[100];
	int bytes_read;
	pid_t pid;

	pid = fork();
	if (pid == 0)
		write(1, "child\n", 5);
	else
    {
		write(1, "parent\n", 6);
        wait(NULL);
    }
	return (0);
}