/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absela <absela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:28:55 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:19 by absela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_data(t_cub *data)
{
	data->ply->walk = 0;
	data->ply->offset = 0;
	data->ply->rotate = 0;
}

t_data	*get_tex(t_cub *data, int i, double *n, double *y)
{
	t_data	*text;

	text = NULL;
	text = &data->txt->noptr;
	if (data->ray[i].touch && data->ray[i].sight == 1)
		text = &data->txt->noptr;
	else if (data->ray[i].touch && data->ray[i].sight == -1)
		text = &data->txt->soptr;
	else if (!data->ray[i].touch && data->ray[i].sight == 1)
		text = &data->txt->weptr;
	else if (!data->ray[i].touch && data->ray[i].sight == -1)
		text = &data->txt->eaptr;
	*n = (text->height / 2);
	*y = HHEITH / 2;
	return (text);
}

void	scale_var(int *m, double *y, double *n, double projection_distance)
{
	*m = -1;
	*y -= (double)(projection_distance / TILE);
	*n -= 1;
	if (*n < 0)
		*n = 0;
}
