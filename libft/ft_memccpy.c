
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*a;
	unsigned char		*b;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	b = (unsigned char *)src;
	a = (unsigned char *)dst;
	while (i != n)
	{
		a[i] = b[i];
		if (a[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
