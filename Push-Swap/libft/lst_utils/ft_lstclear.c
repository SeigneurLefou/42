#include "libps.h"

void	ft_lstclear(t_list **lst, void (*del)(long))
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !del || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
		del(last->value);
		free(last);
	}
	*lst = NULL;
}
