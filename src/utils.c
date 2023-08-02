/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:54:47 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/02 13:04:11 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*filter_path(char **envp, char *cmd)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_all(paths);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;

	i = 0;
	if (!cmd || ft_strnstr(cmd, "/", 2) != NULL)
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (filter_path(envp, cmd));
}

void	execute(char *argv, char **envp, int *dups)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_all(cmd);
		close_fd(dups);
		ft_error("pipex: command not found");
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_all(cmd);
		free(path);
		close_fd(dups);
		ft_error(NULL);
	}
}
// execve duplicates the process again,
// so if i write a printf after it it will not run.