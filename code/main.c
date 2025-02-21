/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:17 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/21 10:59:37 by iheb             ###   ########.fr       */
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