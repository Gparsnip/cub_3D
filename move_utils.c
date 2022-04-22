
#include "cub3d.h"

int	check_step_right(t_all	*all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (all->key.keycode == D)
	{
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		y += (STEP + 50) * sin((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (0);
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (1);
		y -= (STEP + 50) * sin((all->turn.alpha * PI / 180) + PI / 2);
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (2);
	}
	return (-1);
}
