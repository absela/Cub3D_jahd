/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:48:45 by absela            #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_ray_angle(double ray_ang, int flag)
{
	if (flag == 1)
	{
		if (ray_ang == 0 || ray_ang == M_PI)
			return (0);
		if (ray_ang > M_PI)
			return (1);
		else
			return (-1);
	}
	else
	{
		if (ray_ang == M_PI / 2 || ray_ang == (3 * M_PI) / 2)
			return (0);
		if (ray_ang > (3 * M_PI) / 2 || ray_ang < M_PI / 2)
			return (1);
		else
			return (-1);
	}
}

void	x_intersection(t_cub *data, double ray_angle,
	double *x_inter, double *y_inter)
{
	int		check;
	double	next_x;
	double	next_y;

	check = get_ray_angle(ray_angle, 1);
	next_y = TILE * check;
	next_x = next_y / -tan(ray_angle);
	if (check != -1)
		*y_inter = (floor(data->ply->y / TILE)) * TILE + TILE;
	else
		*y_inter = (floor(data->ply->y / TILE)) * TILE;
	*x_inter = data->ply->x + (data->ply->y - *y_inter) / tan(ray_angle);
	if (check == -1)
		*y_inter -= ADJ;
	while (*x_inter / TILE > 0 && (*x_inter / TILE) < data->map_lines && \
			data->map_final[(int)floor(*y_inter / TILE)]
		[(int)floor(*x_inter / TILE)] != '1')
	{
		*x_inter += next_x;
		*y_inter += next_y;
	}
}

void	get_x_ray(t_cub *data, double ray_angle, t_ray *ray_info)
{
	double	x_inter;
	double	y_inter;
	int		check;

	check = get_ray_angle(ray_angle, 1);
	if (!check)
	{
		ray_info->distance = INFINITY;
		return ;
	}
	x_intersection(data, ray_angle, &x_inter, &y_inter);
	ray_info->x = x_inter;
	ray_info->y = y_inter;
	ray_info->touch = 1;
	if (get_ray_angle(ray_angle, 1) == 1)
		ray_info->sight = 1;
	else
		ray_info->sight = -1;
	ray_info->distance = sqrt(pow((data->ply->x - x_inter), 2) + \
		pow((data->ply->y - y_inter), 2));
}

void	y_intersection(t_cub *data, double ray_angle,
	double *x_inter, double *y_inter)
{
	int		check;
	double	next_x;
	double	next_y;

	check = get_ray_angle(ray_angle, 2);
	next_x = TILE * check;
	next_y = next_x * -tan(ray_angle);
	if (check != -1)
		*x_inter = (floor(data->ply->x / TILE) * TILE) + TILE;
	else
		*x_inter = (floor(data->ply->x / TILE) * TILE);
	*y_inter = data->ply->y + (data->ply->x - *x_inter) * tan(ray_angle);
	if (check == -1)
		*x_inter -= ADJ;
	while (*y_inter / TILE > 0 && (*y_inter / TILE) < ft_tablen(data->map_final)
		&& data->map_final[(int)floor(*y_inter / TILE)]
		[(int)floor(*x_inter / TILE)] != '1')
	{
		*x_inter += next_x;
		*y_inter += next_y;
	}
}

void	get_y_ray(t_cub *data, double ray_angle, t_ray *ray_info)
{
	double	x_inter;
	double	y_inter;
	int		check;

	check = get_ray_angle(ray_angle, 2);
	if (!check)
	{
		ray_info->distance = INFINITY;
		return ;
	}
	y_intersection(data, ray_angle, &x_inter, &y_inter);
	if (ray_info->distance > sqrt(pow((data->ply->x - x_inter), 2)
			+ pow((data->ply->y - y_inter), 2)))
	{
		ray_info->x = x_inter;
		ray_info->y = y_inter;
		ray_info->touch = 0;
		if (get_ray_angle(ray_angle, 2) == 1)
			ray_info->sight = 1;
		else
			ray_info->sight = -1;
		ray_info->distance = sqrt(pow((data->ply->x - x_inter), 2)
				+ pow((data->ply->y - y_inter), 2));
	}
}
