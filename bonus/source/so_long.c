#include "../so_long.h"
#include "../minilibx/mlx.h"

int	ft_exit(t_map *map)
{
	return (exitt(map), 0);
}

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
	map->number_of_steps++;
	if (map->mav[map->p_loc[1]][map->p_loc[0]] == 'C')
	{
		map->mav[map->p_loc[1]][map->p_loc[0]] = '0';
		map->c_cont--;
	}
	else if (map->c_cont == 0 && map->mav[map->p_loc[1]][map->p_loc[0]] == 'E')
		exitt(map);
	return (0);
}

int	render(t_map *map)
{
	mlx_clear_window(map->ptr, map->win);
	render_basic(map);
	render_animation(map);
	render_enemies(map);
	render_score(map);
	mlx_put_image_to_window
		(map->ptr, map->win, map->player,
		map->p_loc[0] * PIXEL, map->p_loc[1] * PIXEL);
	return (0);
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
	init_animation(map);
	init_enemies(map);
	init_control(map);
	run_mlx(map);
}
