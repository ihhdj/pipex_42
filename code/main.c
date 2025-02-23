/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:17 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/23 11:23:26 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int main(int argc, char **argv, char **env)
{
    t_pipe pipe;

	init_struct(&pipe);
	parsing(argc, argv, env, &pipe);
	clean(&pipe);
    return (0);
}

void    init_struct(t_pipe *pipe)
{
    pipe->cmd_path = NULL;
    pipe->cmd_path1 = NULL;
    pipe->cmd_args = NULL;
    pipe->cmd_args1 = NULL;
}