#ifndef CUB_H
# define CUB_H

//std includes
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <dirent.h>

//project includes
# include "libft.h"
# include "fixed.h"
# include "gc.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

//types includes
# include "fixed_types.h"
# include "cub_types.h"
# include "listft.h"
# include "engine.h"

//macros
# define WIN_SIZE_W 1028
# define WIN_SIZE_H 720
# define TILE_SIZE 64

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    render(t_cub *cub);
int		parser(int fd, t_cub *cub);
int		import_elements(t_cub *cub);
int		file_validator(char *map_path);
int		game_init(t_cub *cub);
void	init_fetch(t_cub *cub);

// minimap
int		draw_minimap(t_cub* cub, int playerx, int playery);
void	minimove(t_cub* cub, int key);


#endif //CUB_H
