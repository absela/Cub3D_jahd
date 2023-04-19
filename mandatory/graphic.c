/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 05:17:16 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/18 22:54:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	angale_range(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle >= (2 * M_PI))
		angle -= 2 * M_PI;
	return (angle);
}

int	regenerate_map_3d(t_cub *data)
{
	moveply(data);
	if (data->mlx->img->img)
	{
		mlx_destroy_image(data->mlx->mlx, data->mlx->img->img);
		mlx_clear_window(data->mlx->mlx, data->mlx->win);
	}
	data->mlx->img->img = mlx_new_image(data->mlx->mlx, WWITH, HHEITH);
	data->mlx->img->addr = mlx_get_data_addr(data->mlx->img->img,
			&data->mlx->img->bits_per_pixel, &data->mlx->img->line_length,
			&data->mlx->img->endian);
	cats_rays(data);
	sky_floor(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
	free(data->ray);
	return (0);
}

void	initialize_mlx(t_cub *data)
{
	data->mlx = malloc(sizeof(t_minilibx));
	if (!data->mlx)
		ft_error("malloc mlx !!\n", data);
	data->mlx->img = malloc(sizeof(t_data));
	if (!data->mlx->img)
		ft_error("malloc mlx !!\n", data);
	data->project = (WWITH / 2) / (tan(FOV / 2));
	data->angl_btw = FOV / (WWITH);
	data->mlx->mlx = mlx_init();
	get_textures(data);
	data->mlx->img->img = mlx_new_image(data->mlx->mlx, WWITH, HHEITH);
	data->mlx->img->addr = mlx_get_data_addr(data->mlx->img->img,
			&data->mlx->img->bits_per_pixel, &data->mlx->img->line_length,
			&data->mlx->img->endian);
}

void	graphic(t_cub *data)
{
	initialize_mlx(data);
	data->mlx->win = mlx_new_window(data->mlx->mlx, WWITH, HHEITH, "cub3d 3D");
	mlx_loop_hook(data->mlx->mlx, regenerate_map_3d, data);
	mlx_hook(data->mlx->win, 17, 0, destruction, data);
	mlx_hook(data->mlx->win, 2, 0, moves, data);
	mlx_hook(data->mlx->win, 3, 0, moves_up, data);
	mlx_loop(data->mlx->mlx);
}
