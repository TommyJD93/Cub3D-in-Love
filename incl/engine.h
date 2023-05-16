#ifndef ENGINE_H
# define ENGINE_H
# include "cub.h"

void	draw_tile(t_cub* cub, unsigned long int color, int w, int h);
void	update_coordinates(int* w, int* h);
void	draw_square(t_cub* cub, unsigned long int color);
void	define_square(t_cub* cub, char tile);
#endif //CUB3D_IN_LOVE_ENGINE_H
