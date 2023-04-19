/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:31:00 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_info(t_cub *data)
{
	parse_each_textures(data->info->ea);
	parse_each_textures(data->info->we);
	parse_each_textures(data->info->no);
	parse_each_textures(data->info->so);
	parse_each_color(data->info->c);
	parse_each_color(data->info->f);
	store_colors(data->info->sky_color, data->info->c);
	store_colors(data->info->floor_color, data->info->f);
}

void	store_player_info(t_cub *data, int i, int j)
{
	data->ply->x = ((double)j * TILE) + TILE / 2;
	data->ply->y = ((double)i * TILE) + TILE / 2;
	if ((data->map_final[i][j]) == 'N')
	{
		data->ply->angle = 3 * M_PI / 2;
	}
	else if ((data->map_final[i][j]) == 'E')
	{
		data->ply->angle = 0;
	}
	else if ((data->map_final[i][j]) == 'W')
	{
		data->ply->angle = M_PI;
	}
	else if ((data->map_final[i][j]) == 'S')
	{
		data->ply->angle = M_PI / 2;
	}
}

void	get_ply_info(t_cub *data)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	i = 0;
	flag = 0;
	while (data->map_final[i])
	{
		while ((data->map_final[i][j]))
		{
			if ((data->map_final[i][j]) == 'N' || (data->map_final[i][j]) == 'E'
			|| (data->map_final[i][j]) == 'W' || (data->map_final[i][j]) == 'S')
			{
				flag++;
				store_player_info(data, i, j);
				data->map_final[i][j] = 'P';
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (flag != 1)
		ft_error("player position error !!\n", data);
}

void	re_allocate_map(t_cub *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->map_final[i])
	{
		tmp = data->map_final[i];
		data->map_final[i] = malloc(sizeof(char) * data->map_lines + 1);
		if (!data->map_final[i])
			ft_error("unable to allocate in re_allocate_map_final  !!!\n", data);
		ft_memcpy(data->map_final[i], tmp, ft_strlen(tmp));
		ft_memset(data->map_final[i] + ft_strlen(tmp), ' ', data->map_lines - \
			ft_strlen(tmp));
		data->map_final[i][data->map_lines] = '\0';
		free(tmp);
		i++;
	}
}

void	fill_map(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_lines - 1)
	{
		while (data->map_final[j])
		{
			if (data->map_final[j][i] != '1' && data->map_final[j][i] != '0' &&
				data->map_final[j][i] != 'P')
				data->map_final[j][i] = '1';
			j++;
		}
		i++;
		j = 0;
	}
}
