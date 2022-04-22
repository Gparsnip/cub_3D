
#include "get_next_line.h"

char	*ft_strjoin1(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen1(s1);
	k = k + ft_strlen1(s2) + 1;
	str = ft_calloc1(sizeof(char), k);
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

int	ft_read(int fd, char **buff, char **rema, char **tmp)
{
	int		letter;

	letter = 0;
	free(*buff);
	*buff = NULL;
	(*buff) = ft_calloc1(sizeof(char), BUFFER_SIZE + 1);
	letter = read(fd, *buff, BUFFER_SIZE);
	if ((*rema) == NULL)
		(*rema) = ft_calloc1(sizeof(char), BUFFER_SIZE + 1);
	if ((*tmp) != NULL)
	{
		free((*rema));
		*rema = NULL;
		*rema = ft_strjoin1(*tmp, "\0");
		if (rema == NULL)
			return (-1);
		free(*tmp);
		*tmp = NULL;
	}
	*tmp = ft_strjoin1(*rema, *buff);
	if (tmp == NULL)
		return (-1);
	return (letter);
}

char	*ft_calloc1(size_t count, size_t size)
{
	size_t	i;
	char	*a;

	i = count * size;
	if (size == 0 || count == 0)
		i = 1;
	a = (char *)malloc(i);
	if (a == NULL)
		return (NULL);
	while (i-- > 0)
	{
		a[i] = '\0';
	}
	return (a);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
