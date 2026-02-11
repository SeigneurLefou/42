/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:17 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/11 11:01:44 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	*ft_getenv(char **env, char *var)
{
	int		i;
	int		len_var_name;
	char	*var_content;

	i = 0;
	len_var_name = ft_strlen(var);
	while (ft_strncmp(env[i], var, len_var_name))
		i++;
	var_content = ft_calloc(sizeof(char), ft_strlen(env[i]) - len_var_name - 1);
	var_content = ft_strcpy(var_content, &env[i][len_var_name + 1]);
	return (var_content);
}

char	*ft_get_cmd_path(t_cmd *cmd, char **env)
{
	char	*path;
	char	**splited_path;
	char	*cmd_path;
	int		i;
	
	path = ft_getenv(env, "PATH");
	splited_path = ft_split(path, ':');
	free(path);
	i = 0;
	cmd_path = ft_strjoin(splited_path[i], cmd->cmd_name);
	while (splited_path[i] && !access(cmd_path, X_OK))
	{
		i++;
		free(cmd_path);
		if (splited_path[i])
			cmd_path = ft_strjoin(splited_path[i], cmd->cmd_name);
	}
	if (!splited_path[i])
		return (NULL);
	cmd_path = ft_strjoin(splited_path[i], "/");
	cmd_path = ft_strjoin(cmd_path, cmd->cmd_name);
	return (cmd_path);
}

void	ft_exec_cmd(t_cmd *cmd, char **env)
{
	char	*path_cmd;

	path_cmd = ft_get_cmd_path(cmd, env);
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

int	ft_fork_pid(int fdin, int *fdout, t_cmd *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		take_child(fdin, fdout[1], cmd, env);
	close(fdin);
	close(fdout[1]);
	return (fdout[0]);
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

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		tmp_fd;
	int		pipe_error;
	int		werror;
	t_cmd	*cmd;

	if (argc < 4) //&& access(argv[1], R_OK) == -1)
		return (1);
	cmd = init_list_cmd(argc - 3, argv + 2);
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
		tmp_fd = ft_fork_pid(tmp_fd, pipe_fd, cmd, env);
		if (tmp_fd == -1)
			return (1);
		cmd = cmd->next;
	}
	waitpid(-1, &werror, 0);
	close(pipe_fd[0]);
	close(tmp_fd);
	return (0);
}
