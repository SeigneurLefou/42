#include "libps.h"

size_t	ft_intslen(const int *list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}
