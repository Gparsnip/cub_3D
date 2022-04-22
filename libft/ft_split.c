
#include "libft.h"

int	ft_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	count_world(char const *s, char c, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = 0;
	if (s[0] != c)
		j = 0;
	while (j != count)
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	while (s[i] != c && s[i] != '\0')
	{
		k++;
		i++;
	}
	return (k);
}

char	*split_world(char const *s, char c, int count, int str)
{
	char	*world;
	int		i;
	int		j;

	i = 0;
	j = -1;
	world = (char *)ft_calloc(sizeof(char), (str + 3));
	if (world == NULL)
		return (NULL);
	if (s[0] != c)
		j = 0;
	while (j != count)
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	j = 0;
	world[j++] = ' ';
	while (j != count_world(s, c, count) + 1)
	{
		world[j] = s[i++];
		j++;
	}
	return (world);
}

void	ft_free_world(int i, char **str)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	str = NULL;
}

char	**ft_split(char const *s, char c, int line)
{
	char	**str;
	int		i;
	int		count;

	i = 0;
	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[0] = ft_calloc(sizeof(char), line + 3);
	while (i != count)
	{
		str[i + 1] = split_world(s, c, i, line);
		if (str[i] == NULL)
		{
			ft_free_world(i, str);
			return (NULL);
		}
		i++;
	}
	str[i + 1] = ft_calloc(sizeof(char), (line + 3));
	str[i + 2] = NULL;
	return (str);
}
