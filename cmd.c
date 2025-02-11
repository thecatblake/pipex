/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:46:04 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/12 03:46:04 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "libft/libft.h"

char	*get_executable(char *bin, char *path)
{
	char	**paths;
	char	*t_path;
	char	*exec_path;

	if (access(bin, X_OK) == 0)
		return (ft_strdup(bin));
	paths = ft_split(path + 5, ':');
	while (*paths)
	{
		t_path = ft_strjoin(*paths, "/");
		exec_path = ft_strjoin(t_path, bin);
		free(t_path);
		if (access(exec_path, X_OK) == 0)
			return (exec_path);
		free(exec_path);
		paths++;
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char **environ)
{
	char	*path;
	char	**args;
	char	*exec_path;

	path = get_path_env(environ);
	args = ft_split(cmd, ' ');
	exec_path = get_executable(args[0], path);
	execve(exec_path, args, environ);
}
