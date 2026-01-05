#include "../libft.h"

void	sa(t_list	*a)
{
	int	tmp;

	if (ft_lstsize(a) < 2)
		return ;
	tmp = a->value;
	a->value = a->next->value; 
	a->next->value = tmp; 
}
