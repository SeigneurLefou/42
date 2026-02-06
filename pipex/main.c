#include "pipex.h"

void	ft_exec_cmd(char *cmd_args, char **env) 
{
	char	**cmd;
	char	*path_cmd;

	cmd = ft_split(cmd_args, ' ');
	path_cmd = ft_strjoin("/usr/bin/", cmd[0]);
	
	execve(path_cmd, cmd, env);
}

void	take_child(int fdin, int fdout, char *cmd, char **env)
{
	dup2(fdin, 0);
	close(fdin);
	dup2(fdout, 1);
	close(fdout);
	ft_exec_cmd(cmd, env);
	exit(127);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		tmp_fd;
	int		pipe_error;
	pid_t	*pid;
	cmd_t	*cmd;
	int		werror;

	if (argc < 5 && access(argv[1], R_OK) == -1)
		return (1);	
	pid = ft_calloc(sizeof(pid_t, argc - 3));
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
			pipe_fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
		pid[cmd->index] = fork();
		if (pid[cmd->index] == -1)
			return (1);
		else if (pid[cmd_index] == 0)
			take_child(tmp_fd, pipe_fd[1], cmd, env);
	}
	while (pid[pid_index])
	{
		werror = waitpid(pid[pid_index], NULL, 0);
		if (werror == -1)
			return (1);
		pid_index++;
	}
	close(pipe_fd[0]);
	close(tmp_fd);
	return (0);
}
