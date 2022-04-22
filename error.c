
#include "cub3d.h"

int	ft_check_double(char *line, t_file *file)
{
	int	i;

	i = 0;
	if (line[0] == 'R' && file->R_x != 0)
		i = -1;
	if (line[0] == 'F' && file->F[1] != 589)
		i = -1;
	if (line[0] == 'C' && file->C[1] != 589)
		i = -1;
	if (line[0] == 'N' && line[1] == 'O' && file->NO_texture != NULL)
		i = -1;
	if (line[0] == 'S' && line[1] == 'O' && file->SO_texture != NULL)
		i = -1;
	if (line[0] == 'W' && line[1] == 'E' && file->WE_texture != NULL)
		i = -1;
	if (line[0] == 'E' && line[1] == 'A' && file->EA_texture != NULL)
		i = -1;
	if (line[0] == 'S' && line[1] != 'O' && file->S_texture != NULL)
		i = -1;
	if (i == -1)
	{
		printf("Error\nDoublicate in file\n");
		exit (-1);
	}
	return (0);
}

void	check_resolution_error(char *line)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (line[++i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				i++;
			count++;
			if (line[i] == '\0')
				break ;
		}
		if (line[i] != ' ')
			print_error(NULL);
	}
	if (count != 2)
		print_error(NULL);
}

void	check_ceiling_floor(char *line)
{
	int	i;
	int	count;
	int	ceil;

	i = 1;
	ceil = 0;
	count = 0;
	while (line[++i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				i++;
			count++;
			if (line[i] == '\0')
				break ;
		}
		if (line[i] != ' ' && line[i] != ',')
			print_error(NULL);
		if (line[i] == ',')
			if (++ceil != count)
				print_error(NULL);
	}
	if (count != 3 || ceil > 2)
		print_error(NULL);
}

int	ft_check_save_file(t_file *file)
{
	if (file->F[0] < 0 || file->F[1] < 0 || file->F[2] < 0
		|| file->F[0] > 255 || file->F[1] > 255 || file->F[2] > 255)
	{
		printf("Error\nInvalid floor color\n");
		return (-1);
	}
	if (file->C[0] < 0 || file->C[1] < 0 || file->C[2] < 0
		|| file->C[0] > 255 || file->C[1] > 255 || file->C[2] > 255)
	{
		printf("Error\nInvalid ceiling color\n");
		return (-1);
	}
	if (ft_check_map(file->map) == -1)
	{
		printf("Error\nMap error\n");
		return (-1);
	}
	return (0);
}

void	print_error(t_all *all)
{
	if (all == NULL)
	{
		printf("Error\nCheck your int in file\n");
		exit (-1);
	}
	if (all->NO_texture.img == NULL)
		printf("Error\nСould not read the wall texture file NO\n");
	if (all->SO_texture.img == NULL)
		printf("Error\nСould not read the wall texture file SO\n");
	if (all->WE_texture.img == NULL)
		printf("Error\nСould not read the wall texture file WE\n");
	if (all->EA_texture.img == NULL)
		printf("Error\nСould not read the wall texture file EA\n");
	if (all->S_texture.img == NULL)
		printf("Error\nСould not read sprite texture file S\n");
}
