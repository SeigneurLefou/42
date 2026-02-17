/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:57:48 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/17 18:34:55 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_child(t_pipex *pipex_var)
{
	dup2(pipex_var->fd[0], 0);
	close(pipex_var->fd[0]);
	dup2(pipex_var->fd[2], 1);
	close(pipex_var->fd[2]);
	close(pipex_var->fd[1]);
	if (!(pipex_var->fd[0] == -1 && pipex_var->cmd->previous == NULL))
		exec_cmd(pipex_var);
	exit(127);
}

int	fork_pid(t_pipex	*pipex_var)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		take_child(pipex_var);
	close(pipex_var->fd[0]);
	close(pipex_var->fd[2]);
	return (pipex_var->fd[1]);
}

int	execution_loop(t_pipex *pipex_var)
{
	int		pipe_error;

	while (pipex_var->cmd)
	{
		if (!(pipex_var->cmd->next) && !access(pipex_var->outfile, F_OK)
			&& access(pipex_var->outfile, W_OK))
			return (0);
		pipe_error = pipe(&pipex_var->fd[1]);
		if (pipe_error)
			return (1);
		if (!(pipex_var->cmd->next))
			pipex_var->fd[2] = open(pipex_var->outfile,
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
		pipex_var->fd[0] = fork_pid(pipex_var);
		if (pipex_var->fd[0] == -1)
			return (1);
		if (!pipex_var->cmd->next)
			return (1);
		pipex_var->cmd = pipex_var->cmd->next;
	}
	return (0);
}
