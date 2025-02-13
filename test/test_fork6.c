/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:05:52 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:02 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

void func(int i, int n)
{
	pid_t pid;
    if (i >= n)
        exit(0);

	pid = fork();
	if (pid == 0)
		func(i + 1, n);
	else
    {
        wait(NULL);
        for (int j =0; j <= i; j++)
            write(1, "child ", 6);
        write(1, "\n", 1);
    }
}

int	main(int argc, char **argv)
{
	int fields[2];
	int buf[100];
	int bytes_read;

    func(0, 6);
    return (0);
}