
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	int					i;
	size_t				j;
	size_t				k;

	i = start - 1;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	while (s[++start - 1] != '\0')
		k++;
	if (k > len)
		k = len;
	str = (char *)malloc(k + 1);
	while (j < k)
		str[++j - 1] = s[++i];
	str[j] = '\0';
	return (str);
}
