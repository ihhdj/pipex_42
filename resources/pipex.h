/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:00:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/20 12:09:11 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/header/ft_printf.h"
# include "libft/header/get_next_line.h"
# include "libft/header/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>

typedef struct s_pipe
{
    char    *path;
    char    *cmd_path;
}   t_pipe;

int	parsing(int argc, char **argv, char **env, t_pipe *pipe);
int	check_acces(char **argv);
char	*find_cmd(char **argv, char **env, t_pipe *pipe);
char	*get_path(char *str, char **env);
void	free_string(char **str);
#endif