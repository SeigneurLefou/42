/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchamard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:46:17 by lchamard          #+#    #+#             */
/*   Updated: 2026/02/16 19:57:15 by lchamard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file_while_not_limiter(int fd, char *limiter, char **buffer)
{
	char	*line;

	line = get_next_line(fd);
	while(line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		*buffer = ft_strjoin(*buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char	*here_doc_file(char **argv)
{
	char	*input_user;
	int		tmp_fd;

	input_user = "";
	get_file_while_not_limiter(0, argv[2], &input_user);
	tmp_fd = open(".truncate_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(tmp_fd, input_user, ft_strlen(input_user));
	close(tmp_fd);
	return (".truncate_file");
}

char	*ft_getenv(t_pipex pipex_var, char *var)
{
	int		i;
	int		len_var_name;
	char	*var_content;

	i = 0;
	len_var_name = ft_strlen(var);
	while (ft_strncmp(pipex_var.env[i], var, len_var_name))
		i++;
	var_content = ft_calloc(sizeof(char), ft_strlen(pipex_var.env[i]) -
				len_var_name);
	var_content = ft_strcpy(var_content, &pipex_var.env[i][len_var_name + 1]);
	return (var_content);
}

char	*ft_get_cmd_path(t_pipex pipex_var)
{
	char	*path;
	char	**splited_path;
	char	*cmd_path;
	int		i;
	
	path = ft_getenv(pipex_var, "PATH");
	splited_path = ft_split(path, ':');
	free(path);
	cmd_path = ft_strjoin(splited_path[0], "/");
	cmd_path = ft_strjoin(cmd_path, pipex_var.cmd->cmd_name);
	i = 1;
	while (splited_path[i])
	{
		cmd_path = ft_strjoin(splited_path[i], "/");
		cmd_path = ft_strjoin(cmd_path, pipex_var.cmd->cmd_name);
		if (!access(cmd_path, X_OK))
			break ;
		i++;
	}
	if (!splited_path[i])
	{
		ft_double_free(splited_path);
		free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}

void	ft_exec_cmd(t_pipex pipex_var)
{
	char	*path_cmd;

	path_cmd = ft_get_cmd_path(pipex_var);
	execve(path_cmd, pipex_var.cmd->cmd_argv, pipex_var.env);
}

void	take_child(t_pipex pipex_var)
{
	dup2(pipex_var.fd[0], 0);
	close(pipex_var.fd[0]);
	dup2(pipex_var.fd[2], 1);
	close(pipex_var.fd[2]);
	close(pipex_var.fd[1]);
	if (pipex_var.fd[0] == -1 && pipex_var.cmd->previous == NULL)
		dprintf(2, "ahahah\n");
	else
		ft_exec_cmd(pipex_var);
	exit(127);
}

int	ft_fork_pid(t_pipex	pipex_var)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		take_child(pipex_var);
	close(pipex_var.fd[0]);
	close(pipex_var.fd[2]);
	return (pipex_var.fd[1]);
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

t_cmd	*init_pipex(int argc, char **argv, char **infile)
{
	int		number_move_right_argv = 2;
	t_cmd	*cmd;

	if (!ft_strcmp(argv[1], "here_doc"))
	{
		number_move_right_argv = 3;
		*infile = here_doc_file(argv);
	}
	else
	{
		number_move_right_argv = 2;
		*infile = argv[1];
	}
	cmd = init_list_cmd(argc - (number_move_right_argv + 1),
		argv + number_move_right_argv);
	return (cmd);
}

int	fake_fdin()
{
	int	fake_pipe[2];

	pipe(fake_pipe);
	close(fake_pipe[1]);
	return (fake_pipe[0]);
}

int execution_loop(t_pipex pipex_var)
{
	int		pipe_error;

	while (pipex_var.cmd)
	{
		if (!(pipex_var.cmd->next) && !access(pipex_var.outfile, F_OK)
			&& access(pipex_var.outfile, W_OK))
			return (0);
		pipe_error = pipe(&pipex_var.fd[1]);
		if (pipe_error)
			return (1);
		if (!(pipex_var.cmd->next))
			pipex_var.fd[2] = open(pipex_var.outfile,
							O_CREAT | O_WRONLY | O_TRUNC, 0644);
		pipex_var.fd[0] = ft_fork_pid(pipex_var);
		if (pipex_var.fd[0] == -1)
			return (1);
		pipex_var.cmd = pipex_var.cmd->next;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		werror;
	char	*infile;
	t_pipex	pipex_var;

	if (!env)
		return (1);
	if (!strcmp(argv[1], "here_doc") && argc < 6)
		return (1);
	if (argc < 5)
		return (1);
	pipex_var.outfile = argv[argc - 1];
	pipex_var.cmd = init_pipex(argc, argv, &infile);
	pipex_var.env = env;
	pipex_var.fd[0] = open(infile, O_RDONLY);
	//if (pipex_var.fd[0] == -1)
	//{
		//pipex_var.fd[0] = dup(STDIN_FILENO);
		//pipex_var.cmd = (pipex_var.cmd)->next;
	//	dprintf(2, "[%s]\n", pipex_var.cmd->cmd_name);
	//}
	if (execution_loop(pipex_var))
		return (1);
	close(pipex_var.fd[0]);
	waitpid(-1, &werror, 0);
	exit(WEXITSTATUS(werror));
}
