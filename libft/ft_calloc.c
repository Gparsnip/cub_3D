
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	char		*a;

	i = count * size;
	if (size == 0 || count == 0)
		i = 1;
	a = (void *)malloc(i);
	if (a == NULL)
		return (NULL);
	a[--i] = '\0';
	while (i-- != 0)
		a[i] = ' ';
	return ((void *)a);
}
