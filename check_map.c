
#include "cub3d.h"

int	ft_check_map(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = -1;
	player = 0;
	if (map == NULL)
		return (-1);
	while (map[i] != NULL)
	{
		while (map[i][++j] != '\0')
		{
			if (ft_check_wall(map, i, j) == -1)
				return (-1);
			if (map[i][j] == 'W' || map[i][j] == 'N'
			|| map[i][j] == 'S' || map[i][j] == 'E')
				player++;
		}
		j = -1;
		i++;
	}
	if (player != 1)
		return (-1);
	return (0);
}

int	ft_check_wall(char **map, int i, int j)
{
	if (i == 0 || map[i + 1] == NULL || map[i + 1][j] == '\0'
		|| j == 0 || map[i][j + 1] == '\0')
	{
		if (map[i][j] != ' ' && map[i][j] != '1')
			i = i + 1 - 1;
	}
	else if (map[i][j] == ' ')
	{
		if (check_space(map, i, j) == -1)
			return (-1);
	}
	else if (map[i][j] != '0' && map[i][j] != 'W'
		&& map[i][j] != '1' && map[i][j] != '2'
		&& map[i][j] != 'E' && map[i][j] != 'N' && map[i][j] != 'S')
		return (-1);
	return (0);
}

int	check_space(char **map, int i, int j)
{
	if ((map[i - 1][j] != '1' && map[i - 1][j] != ' '
		&& map[i - 1][j] != '\0')
		|| (map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != ' '
		&& map[i - 1][j - 1] != '\0')
		|| (map[i][j - 1] != '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '\0')
		|| (map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != ' '
		&& map[i + 1][j - 1] != '\0')
		|| (map[i + 1][j] != '1' && map[i + 1][j] != ' '
		&& map[i + 1][j] != '\0')
		|| (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != ' '
		&& map[i + 1][j + 1] != '\0')
		|| (map[i][j + 1] != '1' && map[i][j + 1] != ' '
		&& map[i][j + 1] != '\0')
		|| (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != ' '
		&& map[i - 1][j + 1] != '\0'))
		return (-1);
	return (0);
}
