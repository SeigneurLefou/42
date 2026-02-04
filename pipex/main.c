#include "pipex.h"

char	**ft_append(char **array, char *element)
{
	int		len;
	char	**result;
	int		i;

	len = 0;
	while (array[len])
		len++;
	result = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (array[i])
	{
		result[i] = array[i];
		i++;
	}
	free(array);
	result[i] = element;
	return (result);
}

void	ft_exec_cmd(char *cmd_args, char **env) 
{
	char	**cmd;
	char	*path_cmd;
	char	*cmd_name;

	cmd = ft_split(cmd_args, ' ');
	cmd_name = cmd[0];
	path_cmd = ft_strjoin("/usr/bin/", cmd_name);
	execve(path_cmd, cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	//char	*outfile;
	int		pipe_fd[2];
	int 	fdio[2];
	int		pipe_error;
	pid_t	pid;
	int		werror;

	if (argc != 5 && access(argv[1], R_OK) == -1)
		return (1);	
	fdio[0] = open(argv[1], O_RDONLY);
	fdio[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	pipe_error = pipe(pipe_fd);
	if (pipe_error)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(fdio[0], 0);
		close(fdio[0]);
		dup2(pipe_fd[1], 1);
		ft_exec_cmd(argv[2], env);
		exit(127);
	}
	werror = waitpid(pid, NULL, 0);
	printf("[%d]", werror);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		dup2(fdio[1], 1);
		ft_exec_cmd(argv[3], env);
		exit(127);
	}
	werror = waitpid(pid, NULL, 0);
	close(fdio[1]);
	return (0);
}
