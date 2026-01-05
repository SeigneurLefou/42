#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(long))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}
