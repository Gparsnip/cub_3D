
#include "libft.h"

int	ft_atoi(const char *str)
{
	int							i;
	int							j;
	long long					c;

	i = 0;
	j = 1;
	c = 0;
	while (str[i] == ' ' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[++i - 1] - '0');
	}
	return ((int)c * j);
}
