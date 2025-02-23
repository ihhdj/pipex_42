/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:37:07 by iheb              #+#    #+#             */
/*   Updated: 2025/02/23 11:23:48 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"


char    **treat_args(char **argv, t_pipe *pipe)
{
    char    **arg;
    arg = ft_split(argv[2], ' ');
    if (!arg)
        return NULL;
    free(arg[0]);
    arg[0] = ft_strdup(pipe->cmd_path);
    if (!arg[0])
    {
        free_string(arg);
        return NULL;
    }
    return(arg);
}

char    **treat_args2(char **argv, t_pipe *pipe)
{
    char    **arg;
    arg = ft_split(argv[3], 32);
    if (!arg)
        return NULL;
    free(arg[0]);
    arg[0] = ft_strdup(pipe->cmd_path1);
    if (!arg[0])
    {
        free_string(arg);
        return NULL;
    }
    return(arg);
}
void    exec_cmd(char **argv, t_pipe *pipex)
{
    int pipefd[2];

    pipex->infile = open(argv[1], O_RDONLY);
    pipex->outfile = open(argv[4], O_WRONLY | O_CREAT);
    pipe(pipefd);
    pipex->process1 = fork();
    if (pipex->process1 == 0)
    {
        dup2(pipex->infile, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close_pipe(pipefd[0], pipefd[1], pipex);
        execve(pipex->cmd_path, pipex->cmd_args, NULL);
    }
    pipex->process2 = fork();
    if (pipex->process2 == 0)
    {
        dup2(pipefd[0], STDIN_FILENO);
        dup2(pipex->outfile, STDOUT_FILENO);
        close_pipe(pipefd[1], pipefd[0], pipex);
        execve(pipex->cmd_path1, pipex->cmd_args1, NULL);
    }
    close_pipe(pipefd[0], pipefd[1], pipex);
    waitpid(pipex->process1, NULL, 0);
    waitpid(pipex->process2, NULL, 0);
}
void	close_pipe(int pipefd1, int pipefd2, t_pipe *pipe)
{
	close(pipefd1);
	close(pipefd2);
	close(pipe->infile);
	close(pipe->outfile);
}

void    clean(t_pipe *pipe)
{
    if (pipe->cmd_path)
        free(pipe->cmd_path);
    if (pipe->cmd_path1)
        free(pipe->cmd_path1);
    if (pipe->cmd_args)
        free_string(pipe->cmd_args);
    if (pipe->cmd_args1)
        free_string(pipe->cmd_args1);
}