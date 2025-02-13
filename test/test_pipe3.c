/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:35:46 by rkaga             #+#    #+#             */
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
	int buf[1000];
	int bytes_read;
	pid_t pid;
	char *path = "/usr/bin/cat";
	char *args[] = {path, "main.c", NULL};

	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
		close(fields[0]);
		dup2(fields[1], 1);
		execve(args[0], args, environ);
	}
	else
	{
		close(fields[1]);
		write(1, "parent\n", 7);
		bytes_read = read(fields[0], buf, 1000);
		write(1, buf, bytes_read);
	}
	return (0);
}
