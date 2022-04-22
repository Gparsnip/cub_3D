
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		l;

	i = -1;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i != len)
	{
		j = 0;
		l = i;
		if (haystack[++i] == needle[j])
		{
			while ((needle[j] != '\0' && haystack[l] != '\0') && l != len)
			{
				if (haystack[l] != needle[j])
					break ;
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
				l++;
			}
		}
	}
	return (NULL);
}
