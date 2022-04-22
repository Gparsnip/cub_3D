
#include "cub3d.h"

int	ft_check_save(t_file *file, char **argv)
{
	char	save[7];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strlcpy(save, "--save", 7);
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] != save[j])
		{
			printf("Error\nInvalid two argument");
			return (-1);
		}
		i++;
		j++;
	}
	file->check_save_image = 1;
	return (0);
}

int	ft_check_argv_help(int argc, char **argv, t_file *file)
{
	char	cub[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strlcpy(cub, "cub", 4);
	while (argv[1][i] != '.')
		i++;
	i++;
	while (argv[1][i++] != '\0')
	{
		if (argv[1][i - 1] != cub[j])
		{
			printf("Error\nInvalid file extension\n");
			return (-1);
		}
		j++;
	}
	if (argc == 3)
	{
		if (ft_check_save(file, argv) == -1)
			return (-1);
	}
	return (0);
}

int	ft_check_argv(int argc, char **argv, t_file *file)
{
	int	fd;
	int	i;
	int	flag_point;

	flag_point = 0;
	i = -1;
	if (argc <= 1 || argc >= 4)
	{
		printf("Error\nWrong number of arguments");
		return (-1);
	}
	while (argv[1][++i] != '\0')
	{
		if (argv[1][i] == '.')
			flag_point = flag_point + 1;
	}
	if (flag_point != 1)
	{
		printf("Error\nInvalid file extension\n");
		return (-1);
	}
	if (ft_check_argv_help(argc, argv, file) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	return (ft_pars(fd, file));
}
