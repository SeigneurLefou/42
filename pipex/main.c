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

	cmd = ft_split(cmd_args, ' ');
	path_cmd = ft_strjoin("/usr/bin/", cmd[0]);
	
	execve(path_cmd, cmd, env);
}

void	take_child(int fdin, int fdout, char *cmd, char **env)
{
	dup2(fdin, 0);
	close(fdin);
	dup2(fdout, 1); // <- PROBLEME
	close(fdout);
	ft_exec_cmd(cmd, env);
	exit(127);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int 	fdio[2];
	int		pipe_error;
	pid_t	pid[2];
	//int		werror;
	int		cmd_index;

	if (argc < 5 && access(argv[1], R_OK) == -1)
		return (1);	
	cmd_index = 0;
	fdio[0] = open(argv[1], O_RDONLY);
	pipe_error = pipe(pipe_fd);
	if (pipe_error)
		return (1);
	pid[0] = fork();
	if (pid[0] == -1)
		return (1);
	else if (pid[0] == 0)
		take_child(fdio[0], pipe_fd[1], argv[2], env);
	close(fdio[0]);
	close(pipe_fd[1]);
	fdio[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	pid[1] = fork();
	if (pid[1] == -1)
		return (1);
	else if (pid[1] == 0)
		take_child(pipe_fd[0], fdio[1], argv[3], env);
	//waitpid(pid[0], NULL, 0);
	//werror = waitpid(pid[1], NULL, 0);
	close(pipe_fd[0]);
	close(fdio[1]);
	return (0);
}
