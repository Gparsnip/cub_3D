
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*a;

	i = 0;
	a = (char *)s;
	while (i != n)
	{
		a[i] = '\0';
		i++;
	}
}
