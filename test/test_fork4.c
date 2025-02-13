/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:04:17 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:02 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

void func()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		write(1, "child\n", 6);
	else
    {
        write(1, "parent\n", 7);
        wait(NULL);
    }
}

int	main(int argc, char **argv)
{
	int fields[2];
	int buf[100];
	int bytes_read;

    func();
    return (0);
}