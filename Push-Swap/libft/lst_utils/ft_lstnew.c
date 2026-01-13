#include "libps.h"

t_list	*ft_lstnew(long content)
{
	t_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = content;
	new_list->index = -1;
	return (new_list);
}
