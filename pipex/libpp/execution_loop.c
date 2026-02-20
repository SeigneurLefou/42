/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:57:48 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/20 10:56:47 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_child(t_pipex *pipex_var, char *path_cmd)
{
	dup2(pipex_var->fd[0], 0);
	close(pipex_var->fd[0]);
	dup2(pipex_var->fd[2], 1);
	close(pipex_var->fd[2]);
	close(pipex_var->fd[1]);
	dprintf(2, "[%s]\n", path_cmd);
	if (path_cmd && !(pipex_var->fd[0] == -1 && !pipex_var->cmd->previous))
		execve(path_cmd, pipex_var->cmd->cmd_argv, pipex_var->env);
	ft_cmdclear(pipex_var->cmd);
	free(path_cmd);
	exit(127);
}

int	fork_pid(t_pipex	*pipex_var, char *path_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		take_child(pipex_var, path_cmd);
	close(pipex_var->fd[0]);
	close(pipex_var->fd[2]);
	return (pipex_var->fd[1]);
}

int	child_gestion(t_pipex *pipex_var)
{
	char	*path_cmd;

	path_cmd = get_cmd_path(pipex_var);
	if (!path_cmd)
	{
		close(pipex_var->fd[1]);
		close(pipex_var->fd[2]);
		return (1);
	}
	pipex_var->fd[0] = fork_pid(pipex_var, path_cmd);
	free(path_cmd);
	if (pipex_var->fd[0] == -1)
		return (1);
	if (!pipex_var->cmd->next)
		return (1);
	pipex_var->cmd = pipex_var->cmd->next;
	return (0);
}

int	execution_loop(t_pipex *pipex_var)
{
	int		pipe_error;

	while (pipex_var->cmd)
	{
		if (!(pipex_var->cmd->next) && !access(pipex_var->outfile, F_OK)
			&& access(pipex_var->outfile, W_OK))
			return (1);
		pipe_error = pipe(&pipex_var->fd[1]);
		if (pipe_error)
			return (1);
		if (!(pipex_var->cmd->next))
		{
			close(pipex_var->fd[2]);
			pipex_var->fd[2] = open(pipex_var->outfile,
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (pipex_var->fd[2] == -1)
				return (1);
		}
		if (child_gestion(pipex_var))
			return (1);
	}
	return (0);
}

int	execution_loop_here_doc(t_pipex *pipex_var)
{
	int		pipe_error;

	while (pipex_var->cmd)
	{
		if (!(pipex_var->cmd->next) && !access(pipex_var->outfile, F_OK)
			&& access(pipex_var->outfile, W_OK))
			return (1);
		pipe_error = pipe(&pipex_var->fd[1]);
		if (pipe_error)
			return (1);
		if (!(pipex_var->cmd->next))
		{
			close(pipex_var->fd[2]);
			pipex_var->fd[2] = open(pipex_var->outfile,
					O_CREAT | O_APPEND | O_WRONLY, 0644);
			if (pipex_var->fd[2] == -1)
				return (1);
		}
		if (child_gestion(pipex_var))
			return (1);
	}
	return (0);
}
