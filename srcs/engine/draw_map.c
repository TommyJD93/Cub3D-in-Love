/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/14 09:57:45 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/engine.h"

void draw_tile(t_cub* cub, unsigned long int color, int w, int h)
{
	int offset;
    int i;

	offset = 10;
	i = 0;
	//i quadratini che rappresentano i caratteri sono di grandezza 13x13
	//con un distacco dal bordo in alto a sinitra di 10 in altezza e larghezza
    while (i < 13)
    {
        int j = 0;
        while (j < 13)
        {
            my_mlx_pixel_put(cub->data, ((h * 13) + (j + offset)), \
				((w * 13) + (i + offset)), color);
            j++;
        }
        i++;
    }
}

void	update_coordinates(int* w, int* h)
{
    (*h)++;
    if (*h == 15)
    {
        (*w)++;
        *h = 0;
    }
    if (*w == 15)
    {
        *h = 0;
        *w = 0;
    }
}

void draw_square(t_cub* cub, unsigned long int color)
{
    static int w = 0;
    static int h = 0;

    draw_tile(cub, color, w, h);
    update_coordinates(&w, &h);
}

void define_square(t_cub* cub, char tile)
{
	if (tile == '\0')
	{
		return ;
	}
	else if (tile == '0')
	{
		draw_square(cub, 0x00101010);
	}
	else if (tile == '1')
	{
		draw_square(cub, 0x00424242);
	}
	else if (tile == ' ')
	{
		draw_square(cub, 0x00694202);
	}
	else if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
	{
		draw_square(cub, 0x00fff000);
	}
	else
	{
		write(1, "Char not printable: Error map\n", \
			ft_strlen("Char not printable: Error map\n"));
	}
}

void draw_borders(t_cub *cub)
{
	int	i;
	int	j;
	int	tiles;

	i = 10;
	tiles = (64 * 3) + 13;
	while (i < tiles)
	{
		j = 10;
		while (j < tiles)
		{
			if ((i == 10 || i == tiles - 1) || (j == 10 || j == tiles - 1))
			{
				my_mlx_pixel_put(cub->data, j, i, 0x0055cc55);
			}
			j++;
		}
		i++;
	}
}

//cicla esattamente i valori +-8 di distanza dal player e disegnali
//se la posizione del player+-8 esce dalla mappa stampa nero

int	draw_minimap(t_cub* cub, int playerx, int playery)
{
	char g_minimappa[15][34] = {
	"1111111111111111111111111        \0",
	"1000000000110000000000001        \0",
	"1011000001110000000000001        \0",
	"1001000000000000000000001        \0",
	"111111111011000001110000000000001\0",
	"100000000011000001110111111111111\0",
	"11110111111111011100000010001    \0",
	"11110111111111N11101010010001    \0",
	"11000000110101011100000010001    \0",
	"10000000000000001100000010001    \0",
	"10000000000000001101010010001    \0",
	"1100000111010101111101111000111  \0",
	"11110111 1110101 101111010001    \0",
	"11111111111111111111111111111    \0",
	"11111111 1111111 111111111111    \0"
};
	int	i;
	int	j;

	int width;
	int	height;

	width = ft_strlen(cub->map[0]) + 17;
	height = row_counter(cub->map) + 16;

	printf("WIDTH: %d\n", width);
	printf("HEIGHT: %d\n", height);
	printf("PLAYERX: %d PLAYERY: %d\n", playerx, playery);

	char** minimap;
	int	k;
	int	m;

	k = 0;
	minimap = (char**) malloc (sizeof(char*) * height);
	for(int i = 0; i < height; i++) {
    	minimap[i] = (char*) malloc (sizeof(char) * width);
	}
	while(k < height)
	{
		m = 0;
		while (m < width)
		{
			minimap[k][m] = '0';
			m++;
		}
		k++;
	}
	k = 0;
	while (k < height - 16)
	{
		m = 0;
		while (m < width - 16)
		{
			minimap[k + 8][m + 8] = g_minimappa[k][m];
			m++;
		}
		k++;
	}

	// for(int i = 0; i < height; i++) {
    // 	for(int j = 0; j < width; j++) {
    //     	printf("%c", minimap[i][j]);
    // 	}
    // 	printf("\n");
	// }

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			{
			//disegna solo i quadrati attorno al player in un area di 8 caselle partendo dal player
			if (((i > playerx - 8) && (i < playerx + 8)) && ((j > playery - 8) && (j < playery + 8)))
				define_square(cub, minimap[i][j]);
			}
			write(1, &minimap[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	draw_borders(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}
