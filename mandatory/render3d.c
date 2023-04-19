/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:03:31 by absela            #+#    #+#             */
/*   Updated: 2023/04/18 22:54:09 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_second_half(int i, double y, t_cub *data, double pd)
{
	int		m;
	double	n;
	t_data	*text;

	text = get_tex(data, i, &n, &y);
	while (y >= ((HHEITH / 2) - (pd / 2))
		&& y > -(double)(pd / TILE))
	{
		scale_var(&m, &y, &n, pd);
		while (++m < pd / TILE)
		{
			if (data->ray[i].touch)
				my_mlx_pixel_put(data->mlx->img, i, (int)y + m,
					*(text->text_int + (int)(n * (text->width)
							+ fmod(data->ray[i].x, TILE))));
			else
				my_mlx_pixel_put(data->mlx->img, i, (int)y + m,
					*(text->text_int + (int)(n * (text->width)
							+ fmod(data->ray[i].y, TILE))));
		}
	}
}

void	draw_texture(int i, double y, t_cub *data, double projection_distance)
{
	int		m;
	double	n;
	t_data	*text;

	text = get_tex(data, i, &n, &y);
	while (y <= (HHEITH / 2) + (projection_distance / 2) && y < HHEITH)
	{
		m = -1;
		while (++m < projection_distance / TILE)
		{
			if (data->ray[i].touch)
				my_mlx_pixel_put(data->mlx->img, i, (int)y + m,
					*(text->text_int + (int)(n * (text->width)
							+ fmod(data->ray[i].x, TILE))));
			else
				my_mlx_pixel_put(data->mlx->img, i, (int)y + m,
					*(text->text_int + (int)(n * (text->width)
							+ fmod(data->ray[i].y, TILE))));
		}
		n++;
		if (n >= text->height)
			n = text->height - 1;
		y += (double)(projection_distance / TILE);
	}
	draw_second_half(i, y, data, projection_distance);
}

t_draw	*init_draw(t_cub *data)
{
	t_draw	*o;

	o = malloc(sizeof(t_draw));
	if (!o)
		perror("cant allocat the t_draw !!\n");
	o->i = 0;
	o->projection_distance = 0;
	o->x = 0;
	o->y = 0;
	o->rgb1 = data->info->sky_color;
	o->rgb2 = data->info->floor_color;
	return (o);
}

void	sky_floor(t_cub *data)
{
	t_draw	*o;

	o = init_draw(data);
	while (o->i < WWITH)
	{
		o->projection_distance = ((TILE * data->project)
				/ (data->ray[o->i].distance));
		while (o->y <= (HHEITH / 2) - (o->projection_distance / 2))
		{
			my_mlx_pixel_put(data->mlx->img, o->i, o->y,
				create_trgb(o->rgb1[0], o->rgb1[1], o->rgb1[2]));
			o->y++;
		}
		draw_texture(o->i, o->y, data, (double)o->projection_distance);
		o->y = (HHEITH / 2) + (o->projection_distance / 2);
		while (o->y < HHEITH)
		{
			my_mlx_pixel_put(data->mlx->img, o->i, o->y,
				create_trgb(o->rgb2[0], o->rgb2[1], o->rgb2[2]));
			o->y++;
		}
		o->y = 0;
		o->i++;
	}
	free(o);
}

int	get_start_txt(t_ray *ray, t_data *txt)
{
	(void)txt;
	if (ray->touch)
		return ((int)ray->x % TILE);
	else
		return ((int)ray->y % TILE);
}
