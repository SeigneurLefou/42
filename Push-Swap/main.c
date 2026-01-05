#include "libft/libft.h"

int main(int argc, char **argv)
{
	long	*res;
	int		i;
	t_list	*stacka;
	t_list	*stackb;

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
	while (i < ft_longslen(res))
	{
		ft_putnbr_fd(res[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	// i = ft_longslen(res) - 1;
	i--;
	stacka = ft_lstnew(res[i]);
	while (i > 0)
	{
		i--;
		stackb = ft_lstnew(res[i]);
		ft_lstadd_front(&stacka, stackb);
		stacka = stackb;
	}
	return (0);
}
