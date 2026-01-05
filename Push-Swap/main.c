#include "libft/libft.h"

int main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	(void)stackb;
	if (argc < 2)
	{
		return (1);
	}
	stacka = ft_parsing(argc, argv);
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_lstiter(stacka, ft_putnbr_endl);
	return (0);
}
