/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:23:38 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:02 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

#define BUF_SIZE 1000000

int	main(int argc, char **argv)
{
	int fields[2];
	int buf[BUF_SIZE];
    int bufw[BUF_SIZE];
	int bytes_read;
    pid_t pid;

    for (int i=0; i < BUF_SIZE; i++) bufw[i] = 'a';

	pipe(fields);
    bytes_read = 1;
    pid = fork();
    if (pid == 0)
    {
        write(fields[1], bufw, BUF_SIZE);
        close(fields[1]);
    }
    else
    {
        close(fields[1]);
        while (bytes_read > 0)
        {
            bytes_read = read(fields[0], buf, BUF_SIZE);
            write(1, buf, bytes_read);
        }
    }
	return (0);
}