/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 04:53:49 by absela            #+#    #+#             */
/*   Updated: 2023/04/18 22:42:56 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	casting(t_cub *data, double ray_angl, t_ray *ray_info)
{
	get_x_ray(data, ray_angl, ray_info);
	get_y_ray(data, ray_angl, ray_info);
}

double	normalize(double ply_angle, double ray_angle, double distance)
{
	if (ray_angle < ply_angle)
		return (distance * cos(ply_angle - ray_angle));
	else
		return (distance * cos(ray_angle - ply_angle));
}

void	cats_rays(t_cub *data)
{
	double	ray_angl;
	int		i;
	int		x;

	i = 0;
	x = WWITH;
	data->ray = malloc(sizeof(t_ray) * x);
	if (!data->ray)
		ft_error("bad allocate !!\n", data);
	while (i < x)
	{
		ray_angl = data->ply->angle - (FOV / 2) + (data->angl_btw * (double)i);
		ray_angl = angale_range(ray_angl);
		data->ray[i].sight = 0;
		data->ray[i].ray_angle = ray_angl;
		casting(data, ray_angl, data->ray + i);
		data->ray[i].distance = normalize(data->ply->angle, ray_angl,
				data->ray[i].distance);
		i++;
	}
}
