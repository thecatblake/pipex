/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:40:19 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/02 08:14:15 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

#define BUF_SIZE 5000

int	func(int outfd, int *fields, char **argv, int n)
{
	pid_t	pid;

	if (n <= 2)
		return (outfd);
	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfd, STDIN_FILENO);
		dup2(fields[1], STDOUT_FILENO);
		close(outfd);
		close(fields[1]);
		execute_cmd(*argv, environ);
	}
	else
	{
		close(outfd);
		wait(NULL);
		outfd = dup(fields[0]);
		close(fields[0]);
		return (func(outfd, fields, argv + 1, n - 1));
	}
	return (0);
}

void	read_and_writefile(int infd, char *path)
{
	int	buf[BUF_SIZE];
	int	bytes_read;
	int	outfd;

	if (access(path, W_OK) != 0)
	{
		outfd = open(path, O_CREAT);
		close(outfd);
	}
	outfd = open(path, O_RDWR);
	bytes_read = read(infd, buf, BUF_SIZE);
	write(outfd, buf, bytes_read);
	close(outfd);
}

int	main(int argc, char **argv)
{
	int		fields[2];
	pid_t	pid;
	int		infd;

	if (argc == 1)
		return (0);
	if (access(argv[1], R_OK) != 0)
		return (write(1, "The first arugment must be readable.\n", 38), 1);
	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
		close(fields[0]);
		dup2(fields[1], STDOUT_FILENO);
		close(fields[1]);
		execute_cmd(ft_strjoin("cat ", argv[1]), environ);
		exit(0);
	}
	close(fields[1]);
	wait(NULL);
	infd = func(dup(fields[0]), fields, (char **)(argv + 2), argc - 1);
	return (read_and_writefile(infd, argv[argc - 1]), 0);
}
