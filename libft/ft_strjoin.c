
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen(s1);
	k = k + ft_strlen(s2);
	str = (char *)malloc(k + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
