/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:46:01 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/19 17:01:22 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(t_pipex *pipex_var, char *var)
{
	int		i;
	int		len_var_name;
	char	*var_content;

	i = 0;
	len_var_name = ft_strlen(var);
	while (ft_strncmp(pipex_var->env[i], var, len_var_name))
		i++;
	var_content = ft_calloc(sizeof(char), ft_strlen(pipex_var->env[i])
			- len_var_name);
	var_content = ft_strcpy(var_content, &pipex_var->env[i][len_var_name + 1]);
	return (var_content);
}

char	*ft_free_path(char *cmd_path, char **splited_path, int i)
{
	if (!splited_path[i])
	{
		free(splited_path);
		return (NULL);
	}
	ft_double_free_start(splited_path, i);
	return (cmd_path);
}

char	*get_cmd_path(t_pipex *pipex_var)
{
	char	*path;
	char	**splited_path;
	char	*cmd_path;
	int		i;

	if (access(pipex_var->cmd->cmd_name, X_OK) != -1)
		return (pipex_var->cmd->cmd_name);
	path = get_env(pipex_var, "PATH");
	splited_path = ft_split(path, ':');
	free(path);
	i = 0;
	while (splited_path[i])
	{
		cmd_path = ft_strjoin(splited_path[i++], "/");
		cmd_path = ft_strjoin(cmd_path, pipex_var->cmd->cmd_name);
		if (access(cmd_path, X_OK) != -1)
			break ;
		free(cmd_path);
	}
	errno = 0;
	cmd_path = ft_free_path(cmd_path, splited_path, i);
	return (cmd_path);
}
