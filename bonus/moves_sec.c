/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 05:13:46 by absela            #+#    #+#             */
/*   Updated: 2023/04/19 10:09:46 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	moveply(t_cub *data)
{
	double	x;	
	double	y;

	x = cos(data->ply->angle) * data->ply->walk * -MVSPEED;
	y = sin(data->ply->angle) * data->ply->walk * MVSPEED;
	if (data->map_final[(int)(data->ply->y + y + (y / 2)) / TILE]
		[(int)(data->ply->x + x + (x / 2)) / TILE] != '1')
	{
		if (data->map_final[(int) data->ply->y / TILE]
			[(int)(data->ply->x + x + (x / 2)) / TILE] != '1' &&
			data->map_final[(int)(data->ply->y + y + (y / 2)) / TILE]
				[(int) data->ply->x / TILE] != '1')
		{
			data->ply->x += x;
			data->ply->y += y;
		}
	}
	try_offset_ply(data, x, y);
	data->ply->angle += data->ply->rotate * TUSPEED;
	data->ply->angle = angale_range(data->ply->angle);
}

double	to_radian(double i)
{
	return (i * M_PI / 180);
}

int	on_mousemove(int x, int y, t_cub *data)
{
	static int	ex;

	if (x < 0 || y < 0 || x > WWITH || y > HHEITH)
		return (0);
	if (x > ex)
		data->ply->angle += 32 * M_PI / WWITH;
	else if (x < ex)
		data->ply->angle -= 32 * M_PI / WWITH;
	ex = x;
	data->ply->angle = angale_range(data->ply->angle);
	return (0);
}
