
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		i;
	int					j;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[i] == c)
		j = i;
	if (j == -1)
		return (NULL);
	return ((char *)s + j);
}
