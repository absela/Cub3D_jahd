/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:50:25 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/28 15:05:10 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t t)
{
	unsigned char	*d;
	size_t			i;	

	i = 0;
	d = str;
	while (t > 0)
	{
		d[i] = (unsigned char)c;
		i++;
		t--;
	}
	return (str);
}
