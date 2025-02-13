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
	pid_t	pid;

	pid = fork();
	if (pid == 0)
    {
        if (i >= n)
        {
			bytes_read = read(fields[0], buf, 1000);
            write(1, buf, bytes_read);
            exit(0);      
        }
        func(fields, i + 1, n);
    }
		
	else
	{
        bytes_read = read(fields[0], buf, 1000);
		write(fields[1], buf, bytes_read);
		wait(NULL);
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
        close(fields[0]);
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
