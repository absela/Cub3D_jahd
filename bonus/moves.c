/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 05:12:31 by absela            #+#    #+#             */
/*   Updated: 2023/04/19 10:51:01 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	destruction(t_cub *data)
{
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	exit(0);
}

int	moves(int keycode, t_cub *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
		data->ply->offset = 1;
	else if (keycode == 1)
		data->ply->walk = 1;
	else if (keycode == 2)
		data->ply->offset = -1;
	else if (keycode == 13)
		data->ply->walk = -1;
	else if (keycode == 123)
		data->ply->rotate = -1;
	else if (keycode == 124)
		data->ply->rotate = 1;
	return (0);
}

int	moves_up(int keycode, t_cub *data)
{
	if (keycode == 1 || keycode == 13)
		data->ply->walk = 0;
	if (keycode == 123 || keycode == 124)
		data->ply->rotate = 0;
	if (keycode == 0 || keycode == 2)
		data->ply->offset = 0;
	return (0);
}

void	extra(t_cub *data, double x, double y)
{
	if (data->ply->offset == 1)
	{
		x = cos(angale_range(data->ply->angle + M_PI / 2)) * -MVSPEED;
		y = sin(angale_range(data->ply->angle + M_PI / 2)) * MVSPEED;
		if (data->map_final[(int)(data->ply->y + y + y / 2) / TILE]
				[(int)(data->ply->x + x + x / 2) / TILE] != '1')
		{
			if (data->map_final[(int) data->ply->y / TILE]
				[(int)(data->ply->x + x + x / 2) / TILE] != '1' &&
				data->map_final[(int)(data->ply->y + y + y / 2) / TILE]
						[(int) data->ply->x / TILE] != '1')
			{
				data->ply->x += x;
				data->ply->y += y;
			}
		}
	}
}

void	try_offset_ply(t_cub *data, double x, double y)
{
	if (data->ply->offset == -1)
	{
		x = cos(angale_range(data->ply->angle - M_PI / 2)) * -MVSPEED;
		y = sin(angale_range(data->ply->angle - M_PI / 2)) * MVSPEED;
		if (data->map_final[(int)(data->ply->y + y + y / 2) / TILE]
				[(int)(data->ply->x + x + x / 2) / TILE] != '1')
		{
			if (data->map_final[(int) data->ply->y / TILE]
				[(int)(data->ply->x + x + x / 2) / TILE] != '1' &&
				data->map_final[(int)(data->ply->y + y + y / 2) / TILE]
						[(int) data->ply->x / TILE] != '1')
			{
				data->ply->x += x;
				data->ply->y += y;
			}
		}
	}
	else
		extra(data, x, y);
}
