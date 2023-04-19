/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:30:50 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	store_info3(char *check, t_cub *data)
{
	if (!ft_strncmp(check, "NO ", 3))
	{
		data->info->no = ft_strtrim(ft_substr(check, 2,
					str_search(check + 2, '\n')), " ");
		data->info->flag_no = 1;
		return (1);
	}
	else if (!ft_strncmp(check, "F ", 2))
	{
		data->info->f = ft_strtrim(ft_substr(check, 1,
					str_search(check + 1, '\n')), " ");
		data->info->flag_f = 1;
		return (1);
	}
	return (0);
}

int	store_info2(char *check, t_cub *data)
{
	if (!ft_strncmp(check, "WE ", 3))
	{
		data->info->we = ft_strtrim(ft_substr(check, 2,
					str_search(check + 2, '\n')), " ");
		data->info->flag_we = 1;
		return (1);
	}
	else if (!ft_strncmp(check, "EA ", 3))
	{
		data->info->ea = ft_strtrim(ft_substr(check, 2,
					str_search(check + 2, '\n')), " ");
		data->info->flag_ea = 1;
		return (1);
	}
	else if (!ft_strncmp(check, "C ", 2))
	{
		data->info->c = ft_strtrim(ft_substr(check, 1,
					str_search(check + 1, '\n')), " ");
		data->info->flag_c = 1;
		return (1);
	}
	else if (store_info3(check, data))
		return (1);
	return (0);
}

int	store_info(char *check, t_cub *data)
{
	if (!ft_strncmp(check, "SO ", 3))
	{
		data->info->so = ft_strtrim(ft_substr(check, 2,
					str_search(check + 2, '\n')), " ");
		data->info->flag_so = 1;
		free(check);
		return (1);
	}
	else if (store_info2(check, data))
	{
		free(check);
		return (1);
	}
	else if (check[0] == '\n')
	{
		free(check);
		return (1);
	}
	free(check);
	return (0);
}

void	parse_each_textures(char *str)
{
	int	fd;

	if (!ft_strncmp(str + ft_strlen(str) - 5, ".xpm", 4))
		ft_error("textures error !!\n", NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("unable to open the textures file !!\n", NULL);
	close (fd);
}

void	parse_each_color(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			ft_error("invalid information in colors !!\n", NULL);
		if (str[i] == ',')
			flag++;
		else if (!ft_isdigit(str[i]))
			ft_error("invalid information in colors !!\n", NULL);
		i++;
	}
	if (flag != 2)
		ft_error("invalid information in colors !!\n", NULL);
}
