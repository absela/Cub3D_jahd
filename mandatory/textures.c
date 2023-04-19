/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 06:38:35 by absela            #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	resize(t_data *ress, t_data *img)
{
	int		x;
	int		y;
	double	sw;
	double	sh;

	sw = img->width / (float)(ress->width);
	sh = img->height / (float)(ress->height);
	x = 0;
	y = 0;
	while (y < ress->height)
	{
		x = 0;
		while (x < ress->width)
		{
			my_mlx_pixel_put(ress, x, y, my_mlx_pixel_get(img, x * sw, y * sh));
			x++;
		}
		y++;
	}
}

void	last_textures(t_data new, t_cub *data)
{
	data->txt->weptr.img = mlx_new_image(data->mlx->mlx, TILE, TILE);
	data->txt->weptr.addr = mlx_get_data_addr(data->txt->weptr.img,
			&data->txt->weptr.bits_per_pixel, &data->txt->weptr.line_length,
			&data->txt->weptr.endian);
	resize(&data->txt->weptr, &new);
	data->txt->weptr.text_int = (unsigned int *)mlx_get_data_addr(
			data->txt->weptr.img, &data->txt->weptr.bits_per_pixel,
			&data->txt->weptr.line_length, &data->txt->weptr.endian);
	new.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->info->ea, &new.width, &new.height);
	if (!new.img)
		ft_error("unable to create image ptr !!\n", data);
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel,
			&new.line_length, &new.endian);
	data->txt->eaptr.img = mlx_new_image(data->mlx->mlx, TILE, TILE);
	data->txt->eaptr.addr = mlx_get_data_addr(data->txt->eaptr.img,
			&data->txt->eaptr.bits_per_pixel,
			&data->txt->eaptr.line_length, &data->txt->eaptr.endian);
	resize(&data->txt->eaptr, &new);
	data->txt->eaptr.text_int = (unsigned int *)mlx_get_data_addr(
			data->txt->eaptr.img, &data->txt->eaptr.bits_per_pixel,
			&data->txt->eaptr.line_length, &data->txt->eaptr.endian);
}

void	next_text(t_data new, t_cub *data)
{
	data->txt->soptr.img = mlx_new_image(data->mlx->mlx, TILE, TILE);
	data->txt->soptr.addr = mlx_get_data_addr(data->txt->soptr.img,
			&data->txt->soptr.bits_per_pixel, &data->txt->soptr.line_length,
			&data->txt->soptr.endian);
	resize(&data->txt->soptr, &new);
	data->txt->soptr.text_int = (unsigned int *)mlx_get_data_addr(
			data->txt->soptr.img, &data->txt->soptr.bits_per_pixel,
			&data->txt->soptr.line_length, &data->txt->soptr.endian);
	new.img = mlx_xpm_file_to_image(data->mlx->mlx, data->info->we,
			&new.width, &new.height);
	if (!new.img)
		ft_error("unable to create image ptr !!\n", data);
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel,
			&new.line_length, &new.endian);
	last_textures(new, data);
}

void	set_textures_size(t_cub *data)
{
	data->txt->noptr.width = TILE;
	data->txt->noptr.height = TILE;
	data->txt->soptr.width = TILE;
	data->txt->eaptr.height = TILE;
	data->txt->eaptr.width = TILE;
	data->txt->soptr.height = TILE;
	data->txt->weptr.width = TILE;
	data->txt->weptr.height = TILE;
}

void	get_textures(t_cub *data)
{
	t_data	new;

	set_textures_size(data);
	data->txt->noptr.img = mlx_new_image(data->mlx->mlx, TILE, TILE);
	data->txt->noptr.addr = mlx_get_data_addr(data->txt->noptr.img,
			&data->txt->noptr.bits_per_pixel, &data->txt->noptr.line_length,
			&data->txt->noptr.endian);
	new.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->info->no, &new.width, &new.height);
	if (!new.img)
		ft_error("unable to create image ptr !!\n", data);
	new.addr = mlx_get_data_addr(new.img,
			&new.bits_per_pixel, &new.line_length, &new.endian);
	resize(&data->txt->noptr, &new);
	data->txt->noptr.text_int = (unsigned int *)mlx_get_data_addr(
			data->txt->noptr.img, &data->txt->noptr.bits_per_pixel,
			&data->txt->noptr.line_length, &data->txt->noptr.endian);
	new.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->info->so, &new.width, &new.height);
	if (!new.img)
		ft_error("unable to create image ptr !!\n", data);
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel,
			&new.line_length, &new.endian);
	next_text(new, data);
}
