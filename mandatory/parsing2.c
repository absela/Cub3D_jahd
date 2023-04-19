/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:30:57 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_my_data(t_cub *data)
{
	data->info = malloc(sizeof(t_info));
	if (!data->info)
		ft_error("unable to allocate !\n", NULL);
	data->ply = malloc(sizeof(t_ply_info));
	if (!data->ply)
		ft_error("unable to allocate !\n", NULL);
	data->info->floor_color = malloc(sizeof(int) * 3);
	if (!data->info->floor_color)
		ft_error("unable to allocate !\n", NULL);
	data->info->sky_color = malloc(sizeof(int) * 3);
	if (!data->info->sky_color)
		ft_error("unable to allocate !\n", NULL);
	data->txt = malloc(sizeof(t_textures));
	if (!data->txt)
		ft_error("unable to allocate !\n", NULL);
	init_data(data);
	data->info->so = NULL;
	data->info->no = NULL;
	data->info->we = NULL;
	data->info->ea = NULL;
	data->info->f = NULL;
	data->info->c = NULL;
	data->map = NULL;
	data->map_name = NULL;
	data->map_final = NULL;
}

char	*r_map(char	*str)
{
	int		check;
	int		fd;
	char	*buf;
	char	*map;

	map = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("unable to open the map!!\n", 2);
		exit(1);
	}
	buf = malloc(2);
	check = read(fd, buf, 1);
	buf[1] = '\0';
	while (check > 0)
	{
		map = ft_strjoin(map, buf);
		check = read(fd, buf, 1);
		buf[1] = '\0';
	}
	free(buf);
	return (map);
}

int	str_search(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	return (i);
}

void	get_map_info(t_cub *data)
{
	char	*check;
	char	*tmp;

	check = data->map;
	while (1)
	{
		if (data->info->flag_so == 1 && data->info->flag_we == 1 && \
			data->info->flag_ea == 1 && data->info->flag_no == 1 && \
			data->info->flag_f == 1 && data->info->flag_c == 1)
		{
			tmp = ft_strdup(check);
			free(data->map);
			data->map = tmp;
			break ;
		}
		if (store_info(ft_strdup(check), data))
			;
		else
			ft_error("+++error in the map contents !\n", NULL);
		check = ft_strchr(check, '\n');
		if (!check)
			ft_error("**error in the map contents !\n", NULL);
		check++;
	}
}

void	store_colors(int	*flor, char *str)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (!tmp || ft_tablen(tmp) != 3)
		ft_error("unable to split !!\n", NULL);
	if (ft_strlen(tmp[0]) > 3 || ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[0]) < 0)
		ft_error("colors numbers are fals !!\n", NULL);
	flor[0] = ft_atoi(tmp[0]);
	if (ft_strlen(tmp[1]) > 3 || ft_atoi(tmp[1]) > 255 || ft_atoi(tmp[1]) < 0)
		ft_error("colors numbers are fals !!\n", NULL);
	flor[1] = ft_atoi(tmp[1]);
	if (ft_strlen(tmp[2]) > 3 || ft_atoi(tmp[2]) > 255 || ft_atoi(tmp[2]) < 0)
		ft_error("colors numbers are fals !!\n", NULL);
	flor[2] = ft_atoi(tmp[2]);
	free_table(tmp);
}
