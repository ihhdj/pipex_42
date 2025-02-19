/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:09:01 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/19 16:10:46 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int	parsing(int argc, char **argv, char **env)
{
	if (argc == 5)
	{
		if (check_acces(argv))
			return (ft_printf("access error\n"), 1);
		find_env(argv, env);
	}
	else
		return (ft_printf("Arguments error\n"), 1);
	return (0);
}

int	check_acces(char **argv)
{
	int fd;

	fd = open(argv[4], O_WRONLY);
	if (access(argv[1], R_OK) == -1)
		return (1);
	if (fd == -1)
	{
		open(argv[4], O_RDWR | O_CREAT, S_IRWXU);
		if (access(argv[4], W_OK) == -1)
		{
			close(fd);
			return (1);
		}
	}
	return (0);
}
char	**get_path(char *str, char **env)
{
}
char	*find_env(char **argv, char **env)
{
	char *path;
	(void)argv;
	path = get_path("PATH", env);
	// printf("%s", path);

	return NULL;
}