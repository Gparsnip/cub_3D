
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (src == NULL)
		return (0);
	j = ft_strlen(src);
	if (dst == NULL || n == 0)
		return (j);
	while (i != n - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
