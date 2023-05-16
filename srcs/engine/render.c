/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:42:53 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/13 17:40:02 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/engine.h"

#define FLOOR 0x0055cc55
#define SKY 0x00aaaaee
#define WALL 0x0

/**
 * @brief raycasting operations for walls
 *
 * @param cub main structure
 */
void	add_walls(t_cub *cub)
{
	t_point		pos0;
	t_point		posf;
	t_fixed8	stepval;

	pos0.x = int2fixed(8);
	pos0.y = int2fixed(5);
	posf.x = int2fixed(200);
	posf.y = int2fixed(200);
	stepval = 0;
	t_point delta = point_delta(pos0, posf);
	if (delta.x > delta.y)
		stepval = delta.x;
	else
		stepval = delta.y;
	//printf("x %.1f, y %.1f\n", fixed2flo(delta.x), fixed2flo(delta.y));
	delta.x = fixdiv(delta.x, stepval);
	delta.y = fixdiv(delta.y, stepval);
	int i = 0;
	while (i++ <= fixed2int(stepval))
	{
		pos0.x = fixsum(pos0.x, delta.x);
		pos0.y = fixsum(pos0.y, delta.y);
		my_mlx_pixel_put(cub->data, fixed2int(pos0.x), fixed2int(pos0.y), WALL);
	}
	//printf("x %.1f, y %.1f\n", fixed2flo(delta.x), fixed2flo(delta.y));
}

/**
 * @brief placeholder function to print on the window and definition of the horizon
 *
 * @param cub main structure
 */
void	render(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	cub->data->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	cub->data->addr = mlx_get_data_addr(cub->data->img,
		&cub->data->bits_per_pixel, &cub->data->line_length, &cub->data->endian);
	for (int y = 0; y < WIN_SIZE_H; y++)
	{
		for (int x = 0; x < WIN_SIZE_W; x++)
		{
			if (y > (WIN_SIZE_H / 2))
				my_mlx_pixel_put(cub->data, x, y, cub->floor_color->rgb);
			else
				my_mlx_pixel_put(cub->data, x, y, cub->ceil_color->rgb);
		}
	}
	add_walls(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
}
