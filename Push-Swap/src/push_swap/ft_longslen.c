#include "libps.h"

size_t	ft_longslen(const long *list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}
