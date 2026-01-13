#include "libps.h"

void	ft_lstiter(t_list **lst, void (*f)(long))
{
	t_list	*tmp;

	if (!(*lst) || !f)
		return ;
	tmp = *lst;
	while (tmp)
	{
		f(tmp->value);
		tmp = tmp->next;
	}
}
