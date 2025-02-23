/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:09:01 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/23 11:24:05 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/pipex.h"

int	parsing(int argc, char **argv, char **env, t_pipe *pipe)
{
	char **cmd;
	char **cmd1;
	if (argc == 5)
	{
		if (check_acces(argv))
			return (ft_printf("access error\n"), 1);
		cmd = ft_split(argv[2], ' ');
		cmd1 = ft_split(argv[3], ' ');
		if (!cmd)
			return (0);
		pipe->cmd_path = find_cmd(cmd[0], env, pipe);
		pipe->cmd_path1 = find_cmd(cmd1[0], env, pipe);
		free_string(cmd);
		free_string(cmd1);
		pipe->cmd_args = treat_args(argv, pipe);
		pipe->cmd_args1 = treat_args2(argv, pipe);
		exec_cmd(argv, pipe);
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
char	*find_cmd(char *cmd, char **env, t_pipe *pipe)
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
		join_path = ft_strjoin(tmp, cmd);
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
