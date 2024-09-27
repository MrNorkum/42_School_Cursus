#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <unistd.h>

int	keyboard(int keycode, t_map *map)
{
	if (keycode == ESC)
		exitt(map);
	else if (keycode == W && map->mav[map->p_loc[1] - 1][map->p_loc[0]] != '1')
		map->p_loc[1]--;
	else if (keycode == A && map->mav[map->p_loc[1]][map->p_loc[0] - 1] != '1')
		map->p_loc[0]--;
	else if (keycode == S && map->mav[map->p_loc[1] + 1][map->p_loc[0]] != '1')
		map->p_loc[1]++;
	else if (keycode == D && map->mav[map->p_loc[1]][map->p_loc[0] + 1] != '1')
		map->p_loc[0]++;
	else
		return (0);
	ft_printf("Number of steps ~> %d\n", ++map->number_of_steps);
	if (map->mav[map->p_loc[1]][map->p_loc[0]] == 'C')
	{
		map->mav[map->p_loc[1]][map->p_loc[0]] = '0';
		map->c_cont--;
	}
	else if (map->c_cont == 0 && map->mav[map->p_loc[1]][map->p_loc[0]] == 'E')
		exitt(map);
	return (0);
}

void	basic_render(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(map->ptr, map->win);
	while (map->mav[++y])
	{
		x = -1;
		while (map->mav[y][++x])
		{
			if (map->mav[y][x] == '1')
				mlx_put_image_to_window
					(map->ptr, map->win, map->wall, x * PIXEL, y * PIXEL);
			else if (map->mav[y][x] == 'C')
				mlx_put_image_to_window
					(map->ptr, map->win, map->coin, x * PIXEL, y * PIXEL);
			else if (map->mav[y][x] == 'E')
				mlx_put_image_to_window
					(map->ptr, map->win, map->exit, x * PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window
					(map->ptr, map->win, map->ground, x * PIXEL, y * PIXEL);
		}
	}
}

int	render(t_map *map)
{
	basic_render(map);
	mlx_put_image_to_window
		(map->ptr, map->win, map->player,
		map->p_loc[0] * PIXEL, map->p_loc[1] * PIXEL);
	return (0);
}
