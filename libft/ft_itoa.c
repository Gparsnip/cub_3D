
#include "libft.h"

int	int_chet(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;

	j = int_chet(n);
	if (n < 0)
		j++;
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	if (j > int_chet(n))
		str[0] = '-';
	str[j] = '\0';
	while (j != 0 && str[j - 1] != '-')
	{
		if (n >= 0)
			str[j-- - 1] = n % 10 + '0';
		else
			str[j-- - 1] = (n % 10 - '0') * -1;
		n = n / 10;
	}
	return (str);
}
