/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:17 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/21 10:23:54 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int main(int argc, char **argv, char **env)
{
	t_pipe pipe;

	parsing(argc, argv, env, &pipe);
    free_string(pipe.cmd_args);
}