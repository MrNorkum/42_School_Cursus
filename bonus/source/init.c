#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	init_mlx(t_map *map)
{
	int		x;
	int		y;

	map->ptr = mlx_init();
	map->win = mlx_new_window
		(map->ptr, map->width * PIXEL, map->height * PIXEL + 360, "so_long");
	map->player = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/player.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/exit.xpm", &x, &y);
	map->ground = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/ground.xpm", &x, &y);
	map->coin = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/coin.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/wall.xpm", &x, &y);
	map->enemyl = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/enemyl.xpm", &x, &y);
	map->enemyr = mlx_xpm_file_to_image
		(map->ptr, "bonus/xpm_file/enemyr.xpm", &x, &y);
}

void	init_animation(t_map *map)
{
	char	*str;
	char	*tmp;
	int		x;
	int		y;
	int		z;

	z = -1;
	while (++z < 146)
	{
		tmp = ft_itoa(z + 1);
		str = ft_strjoin("bonus/wolfsValley/", tmp);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, ".xpm");
		map->animation[z] = mlx_xpm_file_to_image(map->ptr, str, &x, &y);
		if (!map->animation[z])
			return (write(1, "Xpm file could not be read\n", 27), exitt(map));
		free(tmp);
		free(str);
	}
}

void	init_enemies(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->en_cont)
	{
		map->enemies[x].enemy = map->enemyr;
		map->enemies[x].is_right = 1;
		map->enemies[x].wait = 0;
	}
}

void	init_control(t_map *map)
{
	if (!map->player || !map->enemyl || !map->enemyr || !map->win)
		return (write(1, "Xpm file could not be read\n", 27), exitt(map));
	if (!map->coin || !map->wall || !map->exit || !map->ground || !map->ptr)
		return (write(1, "Xpm file could not be read\n", 27), exitt(map));
}
