#include "../so_long.h"
#include "../minilibx/mlx.h"
#include <unistd.h>

int	ft_exit(t_map *map)
{
	return (exitt(map), 0);
}

void	init_mlx(t_map *map)
{
	int	x;
	int	y;

	map->ptr = mlx_init();
	map->win = mlx_new_window
		(map->ptr, map->width * PIXEL, map->height * PIXEL, "so_long");
	map->player = mlx_xpm_file_to_image
		(map->ptr, "basic/xpm_file/player.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image
		(map->ptr, "basic/xpm_file/exit.xpm", &x, &y);
	map->ground = mlx_xpm_file_to_image
		(map->ptr, "basic/xpm_file/ground.xpm", &x, &y);
	map->coin = mlx_xpm_file_to_image
		(map->ptr, "basic/xpm_file/coin.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image
		(map->ptr, "basic/xpm_file/wall.xpm", &x, &y);
}

void	init_control(t_map *map)
{
	if (!map->player || !map->exit || !map->ground)
		return (write(1, "Xpm file could not be read\n", 27), exitt(map));
	if (!map->coin || !map->wall)
		return (write(1, "Xpm file could not be read\n", 27), exitt(map));
}

void	run_mlx(t_map *map)
{
	mlx_hook(map->win, 2, 0, keyboard, map);
	mlx_hook(map->win, 17, 0, ft_exit, map);
	mlx_loop_hook(map->ptr, render, map);
	mlx_loop(map->ptr);
}

void	so_long(t_map *map)
{
	init_mlx(map);
	init_control(map);
	run_mlx(map);
}
