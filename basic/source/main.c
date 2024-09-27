#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	exitt(t_map *map)
{
	free_malloc(map->mav, 0);
	free_malloc(map->virtual_map, 0);
	if (!!map->win)
		mlx_destroy_window(map->ptr, map->win);
	if (!!map->ptr)
		free(map->ptr);
	exit(1);
}

void	init(t_map *map)
{
	map->c_cont = 0;
	map->e_cont = 0;
	map->p_cont = 0;
	map->ctrl_c_cont = 0;
	map->door_accessible = 0;
	map->number_of_steps = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (write(1, "ac != 2\n", 8), 0);
	init(&map);
	checker(av, &map);
	so_long(&map);
}
