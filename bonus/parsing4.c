/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:33:15 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/19 10:10:01 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	check_map(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_final[i])
	{
		while (data->map_final[i][j])
		{
			if (data->map_final[i][j] == '0' || data->map_final[i][j] == 'P')
			{
				if (data->map_final[i + 1] == NULL || j < 1 || i < 1 || \
				data->map_final[i + 1][j] == ' ' || data->map_final[i - 1][j]
				== ' ' || data->map_final[i][j - 1] == ' ' || \
				data->map_final[i][j + 1] == ' ' || \
				data->map_final[i][j + 1] == '\0')
					ft_error("map is not closed\n", data);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	mutate_map(t_cub *data)
{
	int	large_line;
	int	large_collumn;
	int	i;

	large_collumn = 0;
	large_line = 0;
	i = 0;
	while (data->map_final[i])
	{
		if (large_line < (int)ft_strlen(data->map_final[i]))
			large_line = (int)ft_strlen(data->map_final[i]);
		i++;
	}
	data->map_lines = large_line;
	re_allocate_map(data);
	check_map(data);
	fill_map(data);
}

void	parse_map(t_cub *data)
{
	int	i;

	i = 0;
	while (data->map[i] == ' ' || (data->map[i]) == '\n')
		i++;
	while ((data->map[i]) == '1' || (data->map[i]) == '0' || \
		(data->map[i]) == 'N' || (data->map[i]) == 'E' || \
		(data->map[i]) == 'W' || (data->map[i]) == 'S' || \
		(data->map[i]) == '\n' || (data->map[i]) == ' ')
	{
		if (data->map[i] == '\n' && (data->map[i + 1] == '\n' || \
			data->map[i + 1] == '\0'))
		{
			ft_error("empty line inside the map !!\n", data);
		}
		i++;
	}
	if ((data->map[i]) != '\0')
		ft_error("map error !!\n", data);
	data->map_final = ft_split(data->map, '\n');
	if (!data->map_final)
		ft_error("split cant allocate !!\n", data);
	get_ply_info(data);
	mutate_map(data);
}

void	read_map(t_cub *data)
{
	data->map = r_map(data->map_name);
	get_map_info(data);
	parse_info(data);
	parse_map(data);
}

void	parse(t_cub *data)
{
	read_map(data);
}
