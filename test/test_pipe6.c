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

void	func(int *fields, int i, int n)
{
	int		buf[1000];
	int		bytes_read;
	char	*wc_path = "/usr/bin/wc";
	char	*wc_args[] = {wc_path, "-l", NULL};
	
	close(fields[1]);
	dup2(fields[0], 0);
	execve(wc_path, wc_args, environ);
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
		dup2(fields[1], 1);
		execve(cat_path, cat_args, environ);	
	}
	else
	{
		wait(NULL);
		func(fields, 0, 6);
	}
	return (0);
}
