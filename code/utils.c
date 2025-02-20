/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:09:01 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/20 11:59:18 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int	parsing(int argc, char **argv, char **env, t_pipe *pipe)
{
	if (argc == 5)
	{
		if (check_acces(argv))
			return (ft_printf("access error\n"), 1);
		pipe->cmd = find_env(argv, env, pipe);
		if (pipe->cmd)
			free(pipe->cmd);
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
char	*get_path(char *str, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str,ft_strlen(str)) == 0)
			return (env[i]);
		i++;
	}
	return NULL;
}
char	*find_env(char **argv, char **env, t_pipe *pipe)
{
	char	**split_path;
	char	*join_path;
	char	*tmp;
	int		i;
	
	pipe->path = get_path("PATH", env);
	split_path = ft_split(pipe->path, ':');
	if (!split_path)
		return NULL;
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		join_path = ft_strjoin(tmp, argv[2]);
		free(tmp);
		if (access(join_path, X_OK) == 0)
		{
			free_string(split_path);
			return (join_path);
		}
		free(join_path);
		i++;
	}
	free_string(split_path);
	return NULL;
}

void	free_string(char **str)
{
	int 	i;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}