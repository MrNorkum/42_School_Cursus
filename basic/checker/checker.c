#include "../so_long.h"

void	checker(char **av, t_map *map)
{
	is_ber(av, map);
	map_split(map);
	is_rectangle(map);
	is_c_e_p(map);
	is_game(map);
}
