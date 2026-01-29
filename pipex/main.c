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

	cmd = ft_split(cmd_args, ' ');
	cmd = ft_append(cmd, infile);
	path_cmd = ft_strjoin("/bin/", cmd[0]);
	execve(path_cmd, cmd, NULL);
}

int	main(int argc, char **argv)
{
	char	*infile;
	//int		pipe_fd[2];
	int 	fdio[2];

	if (argc != 5)
		return (1);	
	fdio[0] = open(argv[1], O_RDONLY);
	fdio[1] = open(argv[4], O_RDONLY);
	if (access(argv[1], R_OK) == -1)
		return (1);
	infile = get_file(fdio[0]);
	//outfile = get_file(fdio[1])
	printf("infile : [%s]\n", infile);
	ft_exec_cmd(infile, argv[2]);
	return (0);
}
