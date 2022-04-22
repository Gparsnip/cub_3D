
#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (dst > src)
	{
		i = len;
		while (i-- != 0)
			a[i] = b[i];
	}
	else
	{
		i = 0;
		while (i != len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
