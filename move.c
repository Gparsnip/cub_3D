
#include "cub3d.h"

void	move(t_all *all)
{
	int	i;

	i = check_step_fwd(all);
	if (all->key.keycode == W && i == 0)
	{
		all->player.x += STEP * cos((all->turn.alpha * PI / 180));
		all->player.y += STEP * sin((all->turn.alpha * PI / 180));
	}
	if (all->key.keycode == W && i == 1)
		all->player.y += STEP * sin((all->turn.alpha * PI / 180));
	if (all->key.keycode == W && i == 2)
		all->player.x += STEP * cos((all->turn.alpha * PI / 180));
	if (all->key.keycode == S && i == 0)
	{
		all->player.x -= STEP * cos((all->turn.alpha * PI / 180));
		all->player.y -= STEP * sin((all->turn.alpha * PI / 180));
	}
	if (all->key.keycode == S && i == 1)
		all->player.y -= STEP * sin((all->turn.alpha * PI / 180));
	if (all->key.keycode == S && i == 2)
		all->player.x -= STEP * cos((all->turn.alpha * PI / 180));
	if (all->key.keycode == D || all->key.keycode == A
		|| all->key.keycode == TURN_RIGHT || all->key.keycode == TURN_LEFT)
		move_utils(all, i);
}

void	move_utils(t_all *all, int i)
{
	if (all->key.keycode == D && i == 0)
	{
		all->player.x += STEP * cos((all->turn.alpha * PI / 180) + PI / 2);
		all->player.y += STEP * sin((all->turn.alpha * PI / 180) + PI / 2);
	}
	if (all->key.keycode == D && i == 1)
		all->player.y += STEP * sin((all->turn.alpha * PI / 180) + PI / 2);
	if (all->key.keycode == D && i == 2)
		all->player.x += STEP * cos((all->turn.alpha * PI / 180) + PI / 2);
	if (all->key.keycode == A && i == 0)
	{
		all->player.x -= STEP * cos((all->turn.alpha * PI / 180) + PI / 2);
		all->player.y -= STEP * sin((all->turn.alpha * PI / 180) + PI / 2);
	}
	if (all->key.keycode == A && i == 1)
		all->player.y -= STEP * sin((all->turn.alpha * PI / 180) + PI / 2);
	if (all->key.keycode == A && i == 2)
		all->player.x -= STEP * cos((all->turn.alpha * PI / 180) + PI / 2);
	if (all->key.keycode == TURN_RIGHT)
		all->turn.alpha += 4;
	if (all->key.keycode == TURN_LEFT)
		all->turn.alpha -= 4;
}

int	check_step_fwd(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (all->key.keycode == W)
	{
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180));
		y += (STEP + 50) * sin((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (0);
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (1);
		y -= (STEP + 50) * sin((all->turn.alpha * PI / 180));
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (2);
		return (-1);
	}
	if (all->key.keycode == S || all->key.keycode == D
		|| all->key.keycode == A)
		return (check_step_back(all));
	return (0);
}

int	check_step_back(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (all->key.keycode == S)
	{
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180));
		y -= (STEP + 50) * sin((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (0);
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (1);
		y += (STEP + 50) * sin((all->turn.alpha * PI / 180));
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180));
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (2);
	}
	if (all->key.keycode == D
		|| all->key.keycode == A)
	{
		return (check_step_left(all));
	}
	return (-1);
}

int	check_step_left(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x;
	y = all->player.y;
	if (all->key.keycode == A)
	{
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		y -= (STEP + 50) * sin((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (0);
		x += (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (1);
		y += (STEP + 50) * sin((all->turn.alpha * PI / 180) + PI / 2);
		x -= (STEP + 50) * cos((all->turn.alpha * PI / 180) + PI / 2);
		if (all->file.map[y / SIZE_CHUNK][x / SIZE_CHUNK] != '1')
			return (2);
	}
	if (all->key.keycode == D)
		return (check_step_right(all));
	return (-1);
}
