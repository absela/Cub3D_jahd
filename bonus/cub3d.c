/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:05:13 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/19 11:03:42 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_cub	*data;

	if (ac != 2 || ft_strlen(av[1]) < 5 || \
		ft_strncmp((av[1] + ft_strlen(av[1]) - 4), ".cub", 4))
		ft_error("arguments error !\n", NULL);
	data = malloc(sizeof(t_cub));
	if (!data)
		ft_error("unable to allocate !", data);
	init_my_data(data);
	data->map_name = ft_strdup(av[1]);
	parse(data);
	graphic(data);
	free_data(data);
}
