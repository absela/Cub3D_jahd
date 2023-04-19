/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:35:30 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/26 08:50:26 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen((char *)s1);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, (void *)s1, i);
	return (str);
}
