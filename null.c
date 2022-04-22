
#include "cub3d.h"

void	ft_file_null(t_file *file)
{
	file->R_x = 0;
	file->R_y = 0;
	file->NO_texture = NULL;
	file->SO_texture = NULL;
	file->WE_texture = NULL;
	file->EA_texture = NULL;
	file->S_texture = NULL;
	file->check_last_str = 0;
	file->max_str = 0;
	file->F[1] = 589;
	file->C[1] = 589;
	file->err_ceil = 0;
	file->err_flo = 0;
	file->err_res = 0;
}

int	all_null(t_all *all)
{
	all->sprite = NULL;
	all->visual.check_sprite = 0;
	all->visual.count_sprite = 0;
	all->player.x = 0;
	all->player.y = 0;
	all->map_length.x = -1;
	all->map_length.y = -1;
	all->pix_for_map.x = 0;
	all->pix_for_map.y = 0;
	all->turn.alpha = 1;
	all->key.keycode = -1;
	if (all_window(all) == -1)
		return (-1);
	all_image(all);
	if (all->WE_texture.img == NULL || all->EA_texture.img == NULL
		|| all->NO_texture.img == NULL || all->SO_texture.img == NULL
		|| all->S_texture.img == NULL)
	{
		print_error(all);
		return (-1);
	}
	all_addr(all);
	return (0);
}

void	all_addr(t_all *all)
{
	all->SO_texture.addr = mlx_get_data_addr(all->SO_texture.img,
			&all->SO_texture.bits_per_pixel, &all->SO_texture.line_length,
			&all->SO_texture.endian);
	all->EA_texture.addr = mlx_get_data_addr(all->EA_texture.img,
			&all->EA_texture.bits_per_pixel, &all->EA_texture.line_length,
			&all->EA_texture.endian);
	all->WE_texture.addr = mlx_get_data_addr(all->WE_texture.img,
			&all->WE_texture.bits_per_pixel, &all->WE_texture.line_length,
			&all->WE_texture.endian);
	all->NO_texture.addr = mlx_get_data_addr(all->NO_texture.img,
			&all->NO_texture.bits_per_pixel, &all->NO_texture.line_length,
			&all->NO_texture.endian);
	all->S_texture.addr = mlx_get_data_addr(all->S_texture.img,
			&all->S_texture.bits_per_pixel, &all->S_texture.line_length,
			&all->S_texture.endian);
}

int	all_window(t_all *all)
{
	if (all->file.check_save_image != 1)
		all->vars.win = mlx_new_window(all->vars.mlx,
				all->file.R_x, all->file.R_y, "cub3D");
	all->data.img = mlx_new_image(all->vars.mlx, all->file.R_x,
			all->file.R_y);
	all->data.addr = mlx_get_data_addr(all->data.img,
			&all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	all->visual.rey_len = (double *)malloc(sizeof(double) * all->file.R_x);
	if (all->visual.rey_len == NULL)
		return (-1);
	return (0);
}

void	all_image(t_all *all)
{
	all->SO_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
			all->file.SO_texture,
			&all->SO_texture.width, &all->SO_texture.height);
	all->WE_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
			all->file.WE_texture,
			&all->WE_texture.width, &all->WE_texture.height);
	all->EA_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
			all->file.EA_texture,
			&all->EA_texture.width, &all->EA_texture.height);
	all->S_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
			all->file.S_texture,
			&all->S_texture.width, &all->S_texture.height);
	all->NO_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
			all->file.NO_texture,
			&all->NO_texture.width, &all->NO_texture.height);
}
