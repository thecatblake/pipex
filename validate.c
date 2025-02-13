/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:07:36 by rkaga             #+#    #+#             */
/*   Updated: 2025/02/14 05:07:36 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "validate.h"
#include "env.h"
#include "cmd.h"

int	is_executable(char *cmd, char **environ)
{
	char	*path;
	char	**args;
	char	*exec_path;
	int		flag;

	path = get_path_env(environ);
	args = ft_split(cmd, ' ');
	exec_path = get_executable(args[0], path);
	ft_freesplit(args);
	flag = exec_path != NULL;
	free(exec_path);
	return (flag);
}

int	is_readable(char *file)
{
	return (access(file, R_OK) == 0);
}
