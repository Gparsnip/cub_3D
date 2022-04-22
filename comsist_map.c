
#include "cub3d.h"

void	consist_map(t_all *all, char **map)
{
	while (map[++all->map_length.y] != NULL)
	{
		all->map_length.x = -1;
		while (all->file.map[all->map_length.y][++all->map_length.x] != '\0')
		{
			if (all->turn.alpha == 1)
			{
				if (map[all->map_length.y][all->map_length.x] == 'S')
					all->turn.alpha = 90;
				if (map[all->map_length.y][all->map_length.x] == 'W')
					all->turn.alpha = 180;
				if (map[all->map_length.y][all->map_length.x] == 'N')
					all->turn.alpha = 270;
				if (map[all->map_length.y][all->map_length.x] == 'E')
					all->turn.alpha = 0;
				if (all->turn.alpha != 1)
				{
					all->player.x = (all->map_length.x) * SIZE_CHUNK;
					all->player.y = (all->map_length.y) * SIZE_CHUNK;
					map[all->map_length.y][all->map_length.x] = '0';
				}
			}
			save_sprite_list(all);
		}
	}
}

void	save_sprite_list(t_all *all)
{
	t_sprite	*new;

	if (all->file.map[all->map_length.y][all->map_length.x] == '2')
	{
		new = all->sprite;
		while (all->sprite != NULL)
			all->sprite = all->sprite->next;
		all->sprite = (t_sprite *)malloc(sizeof(t_sprite));
		if (all->sprite == NULL)
			exit(-1);
		all->sprite->x = all->map_length.x * SIZE_CHUNK + (SIZE_CHUNK / 2.0);
		all->sprite->y = all->map_length.y * SIZE_CHUNK + (SIZE_CHUNK / 2.0);
		all->sprite->next = new;
	}
}

void	check_resolution(t_file *file)
{
	int	max_size_x;
	int	max_size_y;

	mlx_get_screen_size(&max_size_x, &max_size_y);
	if (file->check_save_image != 1
		&& (file->R_x > max_size_x))
		file->R_x = max_size_x;
	if (file->check_save_image != 1
		&& (file->R_y > max_size_y))
		file->R_y = max_size_y;
}
