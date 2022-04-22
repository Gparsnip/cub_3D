
#include "cub3d.h"

void	create_bmp(t_all *all)
{
	int				fd;
	int				size_file;
	int				x;
	int				y;
	unsigned int	color;

	y = all->file.R_y - 1;
	size_file = (54 + (all->file.R_y * all->file.R_x * 3));
	open("screen.bmp", O_CREAT, S_IRWXU);
	fd = open("./screen.bmp", O_WRONLY);
	ft_putstr_fd("BM", fd);
	create_bmp_help(all, fd, size_file);
	while (y != 0)
	{
		x = 0;
		while (x < all->file.R_x)
		{
			color = get_color(&all->data, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
	}
	all->file.check_save_image = 0;
	close(fd);
}

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	create_bmp_help(t_all *all, int fd, int size_file)
{
	print_byts_offset(size_file, fd);
	print_byts(0, 4, fd);
	print_byts(54, 4, fd);
	print_byts(40, 4, fd);
	print_byts_offset(all->file.R_x, fd);
	print_byts_offset(all->file.R_y - 1, fd);
	print_byts(1, 2, fd);
	print_byts(24, 2, fd);
	print_byts(0, 24, fd);
}

void	print_byts(unsigned char byts, int count, int fd)
{
	while (count != 0)
	{
		ft_putchar_fd(byts, fd);
		byts = 0;
		count--;
	}
}

void	print_byts_offset(int value, int fd)
{
	ft_putchar_fd((unsigned char)value, fd);
	ft_putchar_fd((unsigned char)(value >> 8), fd);
	ft_putchar_fd((unsigned char)(value >> 16), fd);
	ft_putchar_fd((unsigned char)(value >> 24), fd);
}
