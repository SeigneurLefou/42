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

void	ft_exec_cmd(char *infile, char *cmd_args) 
{
	char	**cmd;
	char	*path_cmd;
	char	*cmd_name;

	(void)infile;
	cmd = ft_split(cmd_args, ' ');
	//cmd = ft_append(cmd, infile);
	cmd_name = cmd[0];
	path_cmd = ft_strjoin("/bin/", cmd_name);
	execve(path_cmd, cmd, NULL);
}

int	main(int argc, char **argv)
{
	char	*infile;
	char	*outfile;
	int		pipe_fd[2];
	int 	fdio[2];
	pid_t		pid;

	if (argc != 5 && access(argv[1], R_OK) == -1)
		return (1);	
	fdio[0] = open(argv[1], O_RDONLY);
	infile = get_file(fdio[0]);
	pid = fork();
	if (!pid)
	{
		dup2(fdio[0], 0);
		dup2(1, pipe_fd[1]);
		exit(0);
	}
	fdio[1] = open(argv[4], O_CREAT | O_WRONLY, 0664);
	pid = fork();
	if (!pid)
	{
		dup2(pipe_fd[0], 0);
		dup2(1, pipe_fd[1]);
		exit(0);
	}
	pid = fork();
	if (!pid)
	{
		dup2(pipe_fd[0], 0);
		dup2(1, fdio[1]);
		exit(0);
	}
	outfile = get_file(fdio[1]);
	printf("infile : [%s], outfile : [%s]\n", infile, outfile);
	//ft_exec_cmd(infile, argv[2]);
	return (0);
}
