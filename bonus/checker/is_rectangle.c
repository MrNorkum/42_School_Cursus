#include "../so_long.h"
#include "../libft/libft.h"
#include <unistd.h>

void	is_rectangle(t_map *map)
{
	int	i;
	int	j;

	map->width = (int)ft_strlen(map->mav[0]);
	i = -1;
	while (map->mav[++i])
	{
		if (map->width != (int)ft_strlen(map->mav[i]))
			return (write(2, "Map is not rectangular!!\n", 25), exitt(map));
		j = -1;
		if (!i || i == map->height - 1)
		{
			while (map->mav[i][++j])
				if (map->mav[i][j] != '1')
					return (write(2, "Map is not closed\n", 17), exitt(map));
		}
		else if (map->mav[i][0] != '1' || map->mav[i][map->width - 1] != '1')
			return (write(2, "Map is not closed\n", 17), exitt(map));
	}
}
