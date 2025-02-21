/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:37:07 by iheb              #+#    #+#             */
/*   Updated: 2025/02/21 10:16:00 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"


char    **treat_args(char **argv, t_pipe *pipe)
{
    char    **arg;
    arg = ft_split(argv[2], 32);
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