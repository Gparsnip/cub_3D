
#include "cub3d.h"

int	render_next_frame(t_all *all)
{
	ft_reycast(all);
	if (all->file.check_save_image == 1)
	{
		create_bmp(all);
		ft_close_exit(all);
	}
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);
	if (all->key.keycode >= 0)
	{
		mlx_destroy_image(all->vars.mlx, all->data.img);
		all->data.img = mlx_new_image(all->vars.mlx,
				all->file.R_x, all->file.R_y);
		all->data.addr = mlx_get_data_addr(all->data.img,
				&all->data.bits_per_pixel, &all->data.line_length,
				&all->data.endian);
		move(all);
	}
	return (0);
}

int	ft_key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		free(all->visual.rey_len);
		if (all->sprite != NULL)
			free_sprite(all);
		exit(-1);
	}
	if (keycode == W || keycode == S || keycode == A
		|| keycode == D || keycode == TURN_LEFT
		|| keycode == TURN_RIGHT)
		all->key.keycode = keycode;
	return (0);
}

int	ft_key_stop(int keycode, t_all *all)
{
	if (keycode == W || keycode == S || keycode == A
		|| keycode == D || keycode == TURN_LEFT
		|| keycode == TURN_RIGHT)
		all->key.keycode = -1;
	return (0);
}

int	ft_window(t_file file)
{
	t_all	all;

	all.vars.mlx = mlx_init();
	if (all.vars.mlx == NULL)
	{
		printf("Error\nLibrary initialization mlx. \n");
		return (-1);
	}
	check_resolution(&file);
	all.file = file;
	if (all_null(&all) == -1)
		return (-1);
	consist_map(&all, all.file.map);
	mlx_loop_hook(all.vars.mlx, render_next_frame, &all);
	if (file.check_save_image != 1)
	{
		mlx_hook(all.vars.win, 2, 1L << 0, ft_key_hook, &all);
		mlx_hook(all.vars.win, 3, 1L << 1, ft_key_stop, &all);
		mlx_hook(all.vars.win, CLOSE, 0, ft_close_exit, &all);
	}
	mlx_loop(all.vars.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_file	file;

	if (ft_check_argv(argc, argv, &file) == -1)
		exit(-1);
	if (ft_check_save_file(&file) == -1)
		exit(-1);
	if (ft_window(file) == -1)
		exit(-1);
	return (0);
}
