
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)b;
	while (i != len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
