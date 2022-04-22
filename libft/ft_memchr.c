
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*a;
	size_t		i;

	a = (char *)s;
	i = 0;
	while (i != n)
	{
		if (*a == c)
			return (a);
		a++;
		i++;
	}
	return (NULL);
}
