/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:27:12 by rkaga             #+#    #+#             */
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
	int		fields[2];
	int		buf[100];
	int		bytes_read;
    pid_t	pid;

	pipe(fields);
	pid = fork();
	if (pid == 0)
	{
		write(fields[1], "child\n", 6);
	}
	else
	{
		write(1, "parent\n", 7);
		bytes_read = read(fields[0], buf, 100);
		write(1, buf, bytes_read);
	}
	return (0);
}