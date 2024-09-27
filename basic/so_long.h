#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map
{
	char	*ber;
	char	*line;
	char	*join;
	char	**mav;
	char	**virtual_map;
	int		p_loc[2];
	int		width;
	int		height;
	int		c_cont;
	int		ctrl_c_cont;
	int		e_cont;
	int		door_accessible;
	int		p_cont;
	int		number_of_steps;
	void	*ptr;
	void	*win;
	void	*coin;
	void	*exit;
	void	*player;
	void	*wall;
	void	*ground;
}		t_map;

void	exitt(t_map *map);
void	is_ber(char **av, t_map *map);
void	map_split(t_map *map);
void	is_rectangle(t_map *map);
void	is_c_e_p(t_map *map);
void	is_game(t_map *map);
void	checker(char **av, t_map *map);
int		keyboard(int keycode, t_map *map);
int		render(t_map *map);
void	so_long(t_map *map);

#endif
