#include "../so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	is_ber(char **av, t_map *map)
{
	map->ber = av[1];
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 5))
		return (write(2, "Not ber file!!\n", 15), exit(1));
}
