
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s11;
	unsigned char	*s22;
	unsigned int	a;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (n > 0 && s11[i] != '\0' && s22[i] != '\0')
	{
		a = s11[i] - s22[i];
		if (s11[i] != s22[i])
			return (a);
		i++;
		n--;
	}
	a = s11[i] - s22[i];
	if (n != 0)
		return (a);
	return (0);
}
