/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:45 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/14 16:58:55 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		fin;

	fin = open(argv[1], O_RDONLY, 0777);
	if (fin == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fin, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fout;

	fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fout == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc != 5)
		ft_error();
	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == 0)
		child_process(argv, envp, fd);
	waitpid(pid1, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}
// ./pipex infile "cmd1" | "cmd2" outfile