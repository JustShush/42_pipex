/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:50 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/28 16:13:06 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// this is so i can use waitpid()
// wait for process to change state
# include <sys/wait.h>

// this is for the errno (its the number of the error msg, then strerr() prints the correct error msg)
#include <errno.h>

// file control options
# include <fcntl.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

// in putstr_fd.c
void	ft_putstr_fd(char *s, int fd);
int		ft_isspace(int c);
// -----------------

// in split.c
char	**ft_split(char const *str, char c);
// -----------------

// in utils.c
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
void	execute(char *argv, char **envp, int *dups);
// -----------------

// in utils2.c
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(char *str);
// -----------------

#endif