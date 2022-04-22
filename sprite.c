
#include "cub3d.h"

void	check_sprite(t_all *all, double step)
{
	t_sprite	*tmp;

	tmp = all->sprite;
	while (all->sprite != NULL)
		check_sprite_utils(all, step);
	all->sprite = tmp;
	all->sprite = sort_list(all->sprite);
	draw_sprite(all);
	all->visual.check_sprite = 0;
}

void	draw_sprite(t_all *all)
{
	t_sprite	*tmp;

	tmp = all->sprite;
	while (all->sprite != NULL)
	{
		print_texture_sprite(all);
		all->sprite = all->sprite->next;
	}
	all->sprite = tmp;
}

void	print_texture_sprite(t_all *all)
{
	int	j;
	int	i;

	i = -1;
	while (i < all->sprite->size - 1)
	{
		i++;
		if (all->sprite->start + i < 0
			|| all->sprite->start + i >= all->file.R_x
			|| all->visual.rey_len[all->sprite->start + i] < all->sprite->dist)
			continue ;
		j = -1;
		while (j < all->sprite->size - 1)
		{
			j++;
			if (all->sprite->y_start + j < 0
				|| all->sprite->y_start + j >= all->file.R_y)
				continue ;
			my_mlx_pixel_put(&all->data, (int)(all->sprite->start + i),
				(int)(all->sprite->y_start + j),
				(int)get_color_image(&all->S_texture,
					(int)(i * all->S_texture.width / all->sprite->size),
					(int)(j * all->S_texture.height / all->sprite->size)));
		}
	}
}

void	check_sprite_utils(t_all *all, double step)
{
	double	teta;

	teta = atan2(all->sprite->y - all->player.y,
			all->sprite->x - all->player.x);
	all->sprite->dist = sqrt(pow(all->sprite->x - all->player.x, 2)
			+ pow(all->sprite->y - all->player.y, 2));
	while (teta - (all->turn.alpha * (PI / 180)) > PI)
		teta -= 2 * PI;
	while (teta - (all->turn.alpha * (PI / 180)) < -PI)
		teta += 2 * PI;
	all->sprite->size = (int)round(((SIZE_CHUNK / 1.9)
				/ all->sprite->dist) * all->visual.dist_screen);
	all->sprite->start = (int)((all->file.R_x - 1) / 2.0
			+ (teta - (all->turn.alpha * (PI / 180)))
			/ step - all->sprite->size / 2.0);
	all->sprite->y_start = (all->file.R_y / 2)
		+ (all->sprite->size / SIZE_CHUNK);
	all->sprite = all->sprite->next;
}
