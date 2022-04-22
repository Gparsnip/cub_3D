
#include "get_next_line.h"

int	ft_search(char *tmp)
{
	int			i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n' && i == 0 && tmp[i + 1] == '\0')
			return (1);
		if (tmp[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_final(char **line, char **rema, char *tmp)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (ft_search(tmp) == 1 && tmp[0] == '\n')
		(*line) = ft_calloc1(sizeof(char), 1);
	else if (ft_search(tmp) > 0)
	{
		(*line) = ft_calloc1(sizeof(char), ft_search(tmp) + 1);
	}
	else
		(*line) = ft_calloc1(sizeof(char), ft_strlen1(tmp) + 1);
	while (tmp[++i] != '\0' && tmp[i] != '\n')
		(*line)[i] = tmp[i];
	(*line)[i] = '\0';
	while (tmp[i] != '\0')
	{
		(*rema)[j] = tmp[++i];
		j++;
	}
	(*rema)[j] = '\0';
}

int	get_next_line(int fd, char **line)
{
	static char	*rema;
	char		*buff;
	char		*tmp;
	int			letter;

	letter = 1;
	tmp = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	buff = ft_calloc1(sizeof(char), BUFFER_SIZE + 1);
	if (ft_search(rema) != 0)
		tmp = ft_strjoin1(rema, buff);
	while (ft_search(tmp) == 0 && letter >= 1)
		letter = ft_read(fd, &buff, &rema, &tmp);
	ft_final(line, &rema, tmp);
	free(buff);
	free(tmp);
	if (letter == 0 && rema[0] == '\0')
	{
		free(rema);
		rema = NULL;
		return (0);
	}
	return (1);
}
