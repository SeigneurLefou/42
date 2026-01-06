#include "libft/libft.h"

static void	print_stack(t_list *stacka, t_list *stackb)
{
	ft_putendl_fd("A\n_", 1);
	ft_lstiter(&stacka, ft_putnbr_endl);
	ft_putendl_fd("\nB\n_", 1);
	ft_lstiter(&stackb, ft_putnbr_endl);
}

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
	stackb = NULL;
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	print_stack(stacka, stackb);
	sa(&stacka);
	print_stack(stacka, stackb);
	pb(&stacka, &stackb);
	pb(&stacka, &stackb);
	pb(&stacka, &stackb);
	print_stack(stacka, stackb);
	rr(&stacka, &stackb);
	print_stack(stacka, stackb);
	rrr(&stacka, &stackb);
	print_stack(stacka, stackb);
	sa(&stacka);
	print_stack(stacka, stackb);
	pa(&stacka, &stackb);
	pa(&stacka, &stackb);
	pa(&stacka, &stackb);
	print_stack(stacka, stackb);
	return (0);
}
