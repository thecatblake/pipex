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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

#define BUF_SIZE 5000

void	func(int *fields, int i, int n)
{
	int		buf[BUF_SIZE];
	int		bytes_read;
	char	*wc_path = "/usr/bin/wc";
	char	*wc_args[] = {wc_path, "-l", NULL};
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fields[0], STDIN_FILENO);
		close(fields[0]);
		bytes_read = read(0, buf, BUF_SIZE);
		write(fields[1], "ok", 2);
		exit(0);
	}
	else
	{
		wait(NULL);
		bytes_read = read(fields[0], buf, BUF_SIZE);
		write(1, buf, bytes_read);
	}
}

int	main(int argc, char **argv)
{
	int		fields[2];
	int		buf[100];
	int		bytes_read;
	pid_t	pid;
	char	*cat_path = "/usr/bin/cat";
	char	*cat_args[] = {cat_path, argv[1], NULL};

	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
		dup2(fields[1], STDOUT_FILENO);
		close(fields[1]);
		execve(cat_path, cat_args, environ);	
	}
	else
	{
		wait(NULL);
		func(fields, 2, argc);
	}
	return (0);
}
