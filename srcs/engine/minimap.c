/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/14 08:02:04 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/engine.h"

//per testare uso la key (cioé il movimento del player), in seguito
//questo valore sará sostituito dall orientamento del player + key
//es: player orientato a nord va avanti con w
//la x rimane uguale mentre la y diminuisce di 1 (si sta muovendo verso l alto)

int	mov_offset_y(int key)
{
	if (key == 2)
		return (1);
	else if (key == 0)
		return (-1);
	return (0);
}

int	mov_offset_x(int key)
{
	if (key == 13)
		return (1);
	else if (key == 1)
		return (-1);
	return (0);
}

void	minimove(t_cub* cub, int key)
{
	int	x;
	int	y;

	x = mov_offset_x(key);
	y = mov_offset_y(key);
	cub->player_pos.x += x;
	cub->player_pos.y += y;
	draw_minimap(cub, cub->player_pos.x, cub->player_pos.y);
}
