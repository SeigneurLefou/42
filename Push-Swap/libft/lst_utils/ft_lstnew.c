#include "../libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = content;
	return (new_list);
}
