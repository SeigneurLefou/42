#include "libft/libft.h"

int main(int argc, char **argv)
{
	int	*res;
	int	i;

	if (argc < 2)
	{
		return (1);
	}
	res = ft_parsing(argc, argv);
	if (!res)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	i = 0;
	while (res[i])
	{
		ft_putnbr_fd(res[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	while (i > 0)
	{
		
		i--;
	}

}
