
#include "libft.h"

int	ft_count_start(char const *s1, char const *set)
{
	int					i;
	long int			j;
	int					k;
	int					count;

	i = 0;
	count = ft_strlen(set);
	k = ft_strlen(s1) - 1;
	j = -1;
	while (j != -2)
	{
		j = -1;
		while (set[++j] != '\0')
		{
			if (set[j] == s1[i])
			{
				k--;
				break ;
			}
		}
		if (j == count)
			j = -2;
		i++;
	}
	return (k);
}

int	ft_count_end(char const *s1, char const *set)
{
	int				k;
	int				i;
	long int		j;
	int				count;

	i = ft_strlen(s1) - 1;
	count = ft_strlen(set);
	k = -1;
	j = -1;
	while (j != -2)
	{
		j = -1;
		while (set[++j] != '\0')
		{
			if (set[j] == s1[i])
			{
				k++;
				break ;
			}
		}
		if (j == count)
			j = -2;
		i--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	k = ft_count_start(s1, set) - ft_count_end(s1, set);
	if (k < 0)
		k = 0;
	str = (char *)malloc(k + 1);
	if (str == NULL)
		return (NULL);
	i = ft_strlen(s1) - k - ft_count_end(s1, set) - 1;
	while (j != k)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
