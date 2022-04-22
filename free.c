
#include "cub3d.h"

void	free_sprite(t_all *all)
{
	t_sprite	*tmp;

	while (all->sprite != NULL)
	{
		tmp = all->sprite->next;
		free(all->sprite);
		all->sprite = tmp;
	}
}

int	ft_close_exit(t_all *all)
{
	free(all->visual.rey_len);
	if (all->sprite != NULL)
		free_sprite(all);
	exit(0);
	return (0);
}
