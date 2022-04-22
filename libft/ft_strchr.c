
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (a + i);
		i++;
	}
	if (s[i] == c)
		return (a + i);
	return (NULL);
}
