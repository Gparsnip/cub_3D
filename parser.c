
#include "cub3d.h"

int	ft_pars(int fd, t_file *file)
{
	char	*line;
	int		i;
	char	*map_line;

	i = 1;
	map_line = NULL;
	ft_file_null(file);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		if (i == -1)
		{
			printf("Error\nFailed to read the file\n");
			return (-1);
		}
		if (ft_file_save(line, file, &map_line) == -1)
			return (-1);
		free(line);
	}
	file->map = ft_split(map_line, '\n', file->max_str);
	free(map_line);
	return (0);
}

int	ft_file_save(char *line, t_file *file, char **map_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_check_double(line, file);
	if (line[0] == 'R' && *map_line == NULL && file->R_x == 0 && line[1] == ' ')
	{
		file->R_x = ft_save_file_int(line, &i, file);
		file->R_y = ft_save_file_int(line, &i, file);
	}
	else if (line[0] == 'F' && *map_line == NULL
		&& file->F[1] == 589 && line[1] == ' ')
		while (j != 3)
			file->F[j++] = ft_save_file_int(line, &i, file);
	else if (line[0] == 'C' && *map_line == NULL
		&& file->C[1] == 589 && line[1] == ' ')
		while (j != 3)
			file->C[j++] = ft_save_file_int(line, &i, file);
	else
		ft_save_file_char(line, file, map_line);
	return (0);
}

int	ft_save_file_int(char *line, int *i, t_file *file)
{
	int	flag;

	flag = 0;
	file->max_str = 1;
	if (line[0] == 'R')
		check_resolution_error(line);
	if (line[0] == 'C' || line[0] == 'F')
		check_ceiling_floor(line);
	while (line[*i] != '\0')
	{
		while (line[*i] < 48 || line[*i] > 57)
			*i += 1;
		flag = *i;
		while (line[*i] >= 48 && line[*i] <= 57)
			*i += 1;
		return (ft_atoi(line + flag));
	}
	return (0);
}

void	ft_save_file_char(char *line, t_file *file, char **map_line)
{
	if (line[0] == 'N' && line[1] == 'O'
		&& line[2] == ' ' && *map_line == NULL)
		file->NO_texture = ft_strtrim(line + 2, " ");
	else if (line[0] == 'S' && line[1] == 'O'
		&& line[2] == ' ' && *map_line == NULL)
		file->SO_texture = ft_strtrim(line + 2, " ");
	else if (line[0] == 'W' && line[1] == 'E'
		&& line[2] == ' ' && *map_line == NULL)
		file->WE_texture = ft_strtrim(line + 2, " ");
	else if (line[0] == 'E' && line[1] == 'A'
		&& line[2] == ' ' && *map_line == NULL)
		file->EA_texture = ft_strtrim(line + 2, " ");
	else if (line[0] == 'S' && line[1] == ' ' && *map_line == NULL)
		file->S_texture = ft_strtrim(line + 2, " ");
	else if (file->R_x != 0 && file->R_y != 0 && file->SO_texture != NULL
		&& file->S_texture != NULL && file->WE_texture != NULL
		&& file->NO_texture != NULL && file->EA_texture != NULL)
		ft_save_map(line, file, map_line);
	else if (line[0] != '\0')
	{
		printf("Error\nInvalid file\n");
		exit(-1);
	}
}

void	ft_save_map(char *line, t_file *file, char **map_line)
{
	char	*tmp;

	if (line[0] != '\0' && file->check_last_str == 1)
	{
		printf("Error\nMap Error\n");
		exit(-1);
	}
	if (ft_strlen(line) > (size_t)file->max_str)
		file->max_str = ft_strlen(line);
	if (line[0] != '\0')
	{
		if (*map_line == NULL)
			*map_line = ft_strjoin(line, "\n");
		else
		{
			tmp = *map_line;
			*map_line = ft_strjoin(tmp, line);
			free(tmp);
			tmp = *map_line;
			*map_line = ft_strjoin(tmp, "\n");
			free(tmp);
		}
	}
	else if (*map_line != NULL)
		file->check_last_str = 1;
}
