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
#include "validate.h"
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
		write(STDOUT_FILENO, "", 0);
		exit(1);
	}
	close(fields[1]);
	close(outfd);
	outfd = dup(fields[0]);
	close(fields[0]);
	return (func(outfd, fields, argv + 1, n - 1));
}

void	read_and_writefile(int infd, char *path)
{
	int	buf[BUF_SIZE];
	int	bytes_read;
	int	outfd;

	outfd = open(path, O_RDWR | O_TRUNC);
	bytes_read = read(infd, buf, BUF_SIZE);
	write(outfd, buf, bytes_read);
	close(outfd);
}

int	check_args(int argc, char **argv)
{
	int	outfd;
	int	i;
	int	flag;

	i = 1;
	if (!is_readable(argv[i++]))
		return (1);
	while (i < argc - 1)
		if (!is_executable(argv[i++], environ))
			flag = 2;
	if (argc == 2)
		return (3);
	if (access(argv[i], W_OK) != 0)
	{
		outfd = open(argv[i], O_CREAT);
		if (outfd < 0)
			flag = 1;
		close(outfd);
	}
	if (access(argv[i], W_OK) != 0)
		flag = 1;
	return (flag);
}

int	validate_args(int argc, char **argv)
{
	int	arg_error;

	arg_error = check_args(argc, argv);
	if (arg_error == 1)
		return (write(2, "File error.\n", 13), 1);
	else if (arg_error == 2)
		write(2, "command not found\n", 18);
	else if (arg_error == 3)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fields[2];
	pid_t	pid;
	int		infd;
	int		arg_error;

	if (argc == 1)
		return (0);
	arg_error = validate_args(argc, argv);
	if (arg_error != 0)
		return (arg_error);
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
	infd = func(dup(fields[0]), fields, (char **)(argv + 2), argc - 1);
	if (arg_error == 3)
		return (write(2, "command not found\n", 18), 1);
	return (read_and_writefile(infd, argv[argc - 1]), 0);
}
