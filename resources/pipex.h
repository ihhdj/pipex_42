/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:00:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/23 11:19:32 by iheb             ###   ########.fr       */
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
    char    *cmd_path1;
    char    **cmd_args;
    char    **cmd_args1;
    int     infile;
    int     outfile;
    pid_t   process1;
    pid_t   process2;
}   t_pipe;

int	parsing(int argc, char **argv, char **env, t_pipe *pipe);
int	check_acces(char **argv);
char	*find_cmd(char *cmd, char **env, t_pipe *pipe);
char	*get_path(char *str, char **env);
void	free_string(char **str);
char    **treat_args(char **argv, t_pipe *pipe);
char    **treat_args2(char **argv, t_pipe *pipe);
void    init_struct(t_pipe *pipe);
void    clean(t_pipe *pipe);
void    exec_cmd(char **argv, t_pipe *pipex);
void	close_pipe(int pipefd1, int pipefd2, t_pipe *pipe);
#endif