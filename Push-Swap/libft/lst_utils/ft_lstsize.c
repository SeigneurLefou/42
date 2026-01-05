#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
