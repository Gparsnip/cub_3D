

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char *)malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}
