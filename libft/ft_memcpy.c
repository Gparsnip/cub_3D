
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (a == NULL && b == NULL)
		return (NULL);
	while (i != n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}
