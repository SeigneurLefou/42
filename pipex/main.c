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

int	main(int argc, char **argv)
{
	char	*infile;
	char	**cmd;
	//int		i;

	(void)argc;
	if (argc != 5)
		return (1);	
	if (access(argv[1], R_OK) == -1)
	{
		strerror(EPERM);
		return (1);
	}
	infile = get_file(argv[1]);
	printf("infile : [%s]\n", infile);
	cmd = ft_split(argv[2], ' ');
	//cmd = ft_append(cmd, infile);
	execve("/bin/ls", cmd, NULL);
	return (0);
}
