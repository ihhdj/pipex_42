/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:09:01 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/19 11:23:58 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int	parsing(int argc, char **argv)
{
	if (argc == 5)
	{
		check_acces(argv);
	}
	else
		return (ft_printf("Arguments error\n"), 1);
	return (0);
}

int	check_acces(char **argv)
{
	if (access(argv[1], R_OK) == -1)
		return(ft_printf("access error\n"), 1);
	if (access(argv[4], W_OK) == -1)
		return(ft_printf("access error1\n"), 1);
	return (0);
}