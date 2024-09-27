#include "../so_long.h"
#include <unistd.h>

void	enemies_loc(t_map *map, int x, int y)
{
	map->enemies[map->en_cont].e_loc[0] = x;
	map->enemies[map->en_cont].e_loc[1] = y;
	map->en_cont++;
}

void	player_loc(t_map *map, int x, int y)
{
	map->p_cont++;
	map->p_loc[0] = x;
	map->p_loc[1] = y;
}

void	is_c_e_p(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->mav[y][x] == 'C')
				map->c_cont++;
			else if (map->mav[y][x] == 'E')
				map->e_cont++;
			else if (map->mav[y][x] == 'B')
				enemies_loc(map, x, y);
			else if (map->mav[y][x] == 'P')
				player_loc(map, x, y);
		}
	}
	if (map->c_cont <= 0 || map->e_cont != 1 || map->p_cont != 1)
		return (write(2, "C_E_P Error\n", 11), exitt(map));
	if (map->en_cont > 20)
		return (write(2, "Too many enemies\n", 17), exitt(map));
}
