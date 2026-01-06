#include "../libft.h"

int	ft_lstsize(t_list **lst)
{
	size_t	len;
	t_list	*tmp;

	len = 0;
	if (!lst)
		return (0);
	tmp = *lst;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
