#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	render_basic(t_map *map)
{
	int	x;
	int	y;

	y = -1;
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

void	render_score(t_map *map)
{
	char	*score;

	score = ft_itoa(map->number_of_steps);
	mlx_string_put(map->ptr, map->win, PIXEL * (map->width / 2 - 1),
		PIXEL / 2 - 4, 0xb0e2ff, "Number of steps ~> ");
	mlx_string_put(map->ptr, map->win,
		PIXEL * (map->width / 2 + 1), PIXEL / 2 - 4, 0xb0e2ff, score);
	free(score);
}

void	render_animation(t_map *map)
{
	mlx_put_image_to_window
		(map->ptr, map->win, map->animation[map->index / 2],
		PIXEL * (map->width - 10) / 2, map->height * PIXEL);
	map->index = ++map->index % 292;
}

void	enemy_wall_ctrl(t_map *map, int x)
{
	if (map->mav[map->enemies[x].e_loc[1]]
		[map->enemies[x].e_loc[0] + 1] == '1')
	{
		map->enemies[x].enemy = map->enemyl;
		map->enemies[x].is_right = 0;
	}
	else if (map->mav[map->enemies[x].e_loc[1]]
		[map->enemies[x].e_loc[0] - 1] == '1')
	{
		map->enemies[x].enemy = map->enemyr;
		map->enemies[x].is_right = 1;
	}
}

void	render_enemies(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->en_cont)
		mlx_put_image_to_window
			(map->ptr, map->win, map->enemies[x].enemy,
			map->enemies[x].e_loc[0] * PIXEL, map->enemies[x].e_loc[1] * PIXEL);
	x = -1;
	while (++x < map->en_cont)
	{
		enemy_wall_ctrl(map, x);
		map->enemies[x].wait++;
		if (map->enemies[x].wait == 20)
		{
			map->enemies[x].wait = 0;
			if (map->enemies[x].is_right)
				map->enemies[x].e_loc[0]++;
			else
				map->enemies[x].e_loc[0]--;
		}
		if (map->enemies[x].e_loc[1] == map->p_loc[1]
			&& map->enemies[x].e_loc[0] == map->p_loc[0])
			exitt(map);
	}
}
