/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:11 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:02 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

#define BUF_SIZE 5000

int	main(int argc, char **argv)
{
	int fields[2];
	int buf[BUF_SIZE];
	int bytes_read;
	pid_t pid;
    int outfd;
	char *path1 = "/usr/bin/cat";
	char *args1[] = {path1, "main.c", NULL};
	char *path2 = "/usr/bin/wc";
	char *args2[] = {path2, "-l", NULL};
    char *path3 = "./identity";
	char *args3[] = {path3, NULL};

	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
        dup2(fields[0], STDIN_FILENO);
		close(fields[0]);
		dup2(fields[1], STDOUT_FILENO);
        close(fields[1]);
		execve(args1[0], args1, environ);
	}
	else
	{
        close(fields[1]);
		wait(NULL);
        outfd = dup(fields[0]);
        close(fields[0]);
	}
    pipe(fields);
    pid = fork();
	if (pid == 0)
	{
        dup2(outfd, STDIN_FILENO);
		close(outfd);
		dup2(fields[1], STDOUT_FILENO);
        close(fields[1]);
		execve(args2[0], args2, environ);
	}
	else
	{
        close(fields[1]);
		wait(NULL);
	}
    bytes_read = read(fields[0], buf, BUF_SIZE);
    write(1, buf, BUF_SIZE);
    close(outfd);
	return (0);
}
