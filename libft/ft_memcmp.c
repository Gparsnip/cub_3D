
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;
	unsigned int		i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (n-- > 0)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
