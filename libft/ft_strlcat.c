/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:42:45 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/29 04:59:43 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	k;
	size_t	v;

	j = 0;
	i = 0;
	k = ft_strlen((char *)src);
	j = ft_strlen((char *)dst);
	v = k + j;
	if (dstsize <= j)
		v = dstsize + k;
	while (src[i] != '\0' && (j + 1) < dstsize)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (v);
}
