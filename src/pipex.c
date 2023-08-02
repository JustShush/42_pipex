/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:45 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/02 13:09:28 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		fin;
	int		dp2[2];

	close(fd[0]);
	fin = open(argv[1], O_RDONLY);
	if (fin == -1)
		ft_error(NULL);
	dp2[0] = dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dp2[1] = dup2(fin, STDIN_FILENO);
	close(fin);
	close(fd[0]);
	execute(argv[2], envp, dp2);
}

void	second_process(char **argv, char **envp, int *fd)
{
	int		fout;
	int		dp2[2];

	close(fd[1]);
	fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fout == -1)
		ft_error(NULL);
	dp2[0] = dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dp2[1] = dup2(fout, STDOUT_FILENO);
	close(fout);
	close(fd[1]);
	execute(argv[3], envp, dp2);
}

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		ft_error("pipex: invalid number of args");
	if (pipe(fd) == -1)
		ft_error(NULL);
	pid1 = fork();
	if (pid1 < 0)
		ft_error(NULL);
	if (pid1 == 0)
		child_process(argv, envp, fd);
	close(fd[1]);
	pid2 = fork();
	if (pid2 < 0)
		ft_error(NULL);
	if (pid2 == 0)
		second_process(argv, envp, fd);
	close(fd[0]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
// ./pipex infile "cmd1" "cmd2" outfile
// the -1 will check against any child pid (could use WAIT_ANY for clarity also)