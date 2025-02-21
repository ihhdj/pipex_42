/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:37:07 by iheb              #+#    #+#             */
/*   Updated: 2025/02/21 11:02:55 by iheb             ###   ########.fr       */
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

void    init_struct(t_pipe *pipe)
{
    pipe->cmd_path = NULL;
    pipe->cmd_path1 = NULL;
    pipe->cmd_args = NULL;
    pipe->cmd_args1 = NULL;
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