/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:50 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/13 12:56:37 by dimarque         ###   ########.fr       */
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
#include <sys/wait.h>

// file control options
# include <fcntl.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

// in utils.c
void	ft_error(void);
// -----------------

#endif