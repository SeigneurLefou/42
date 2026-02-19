/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:46:01 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/19 11:47:25 by lchamard         ###   ########.fr       */
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

char	*get_cmd_path(t_pipex *pipex_var)
{
	char	*path;
	char	**splited_path;
	char	*cmd_path;
	int		i;

	if (!access(pipex_var->cmd->cmd_name, X_OK)) // ERROR
		return (pipex_var->cmd->cmd_name);
	path = get_env(pipex_var, "PATH");
	splited_path = ft_split(path, ':');
	free(path);
	i = 0;
	while (splited_path[i])
	{
		cmd_path = ft_strjoin(splited_path[i++], "/");
		cmd_path = ft_strjoin(cmd_path, pipex_var->cmd->cmd_name);
		if (!access(cmd_path, X_OK))
			break ;
	}
	if (!splited_path[i])
	{
		ft_double_free(splited_path);
		free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}

void	exec_cmd(t_pipex *pipex_var, char *path_cmd)
{
	execve(path_cmd, pipex_var->cmd->cmd_argv, pipex_var->env);
}
