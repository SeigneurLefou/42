/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:17 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/09 17:39:17 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(t_cmd *cmd, char **env) 
{
	char	*path_cmd;

	path_cmd = ft_strjoin("/usr/bin/", cmd->cmd_name);
	execve(path_cmd, cmd->cmd_argv, env);
}

void	take_child(int fdin, int fdout, t_cmd *cmd, char **env)
{
	dup2(fdin, 0);
	close(fdin);
	dup2(fdout, 1);
	close(fdout);
	ft_exec_cmd(cmd, env);
	exit(127);
}

int	ft_waitallpid(pid_t *pid)
{
	int		pid_index;
	int		werror;

	pid_index = 0;
	while (pid[pid_index])
	{
		werror = waitpid(pid[pid_index], NULL, 0);
		if (werror == -1)
			return (1);
		pid_index++;
	}
	return (werror);
}

t_cmd	*init_list_cmd(int argc, char **argv)
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*new;

	i = 1;
	cmd = ft_cmdnew(argv[0], 0);
	while (i < argc)
	{
		new = ft_cmdnew(argv[i], i);
		ft_cmdadd_back(&cmd, &new);
		i++;
	}
	return (cmd);
}

void	ft_cmdshow(t_cmd *cmd)
{
	t_cmd	*tmp;
	int	i;

	tmp = cmd;
	i = 0;
	while (tmp)
	{
		ft_printf("name : [%s]\n", tmp->cmd_name);
		while (tmp->cmd_argv[i])
		{
			ft_printf("argv[%d] : [%s]\n", i, tmp->cmd_argv[i]);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		tmp_fd;
	int		pipe_error;
	pid_t	*pid;
	t_cmd	*cmd;

	if (argc < 4 && access(argv[1], R_OK) == -1)
		return (1);	
	cmd = init_list_cmd(argc - 3, argv + 2);
	ft_cmdshow(cmd);
	pid = ft_calloc(sizeof(pid_t), ft_cmdsize(&cmd));
	if (!pid)
		return (1);
	while (cmd)
	{
		pipe_error = pipe(pipe_fd);
		if (pipe_error)
			return (1);
		if (!(cmd->previous))
			tmp_fd = open(argv[1], O_RDONLY);
		if (!(cmd->next))
			pipe_fd[1] = open(argv[argc - 1],
					O_CREAT | O_WRONLY | O_TRUNC, 0664);
		pid[cmd->index] = fork();
		if (pid[cmd->index] == -1)
			return (1);
		else if (pid[cmd->index] == 0)
			take_child(tmp_fd, pipe_fd[1], cmd, env);
		cmd = cmd->next;
	}
	close(pipe_fd[0]);
	close(tmp_fd);
	return (0);
}
