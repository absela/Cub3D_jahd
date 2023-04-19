/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:16:52 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/22 08:05:34 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dist, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dist;
	s = (char *)src;
	if (!dist && !src)
		return (0);
	if (dist < src)
	{
		while (0 < n--)
			*d++ = *s++;
	}
	else
	{
		while (0 < n)
		{
			d[n - 1] = s[n -1];
			n--;
		}
	}
	return (dist);
}
