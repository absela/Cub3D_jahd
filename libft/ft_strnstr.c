/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:28:22 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/29 05:04:32 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen((char *)s2) > ft_strlen((char *)s1))
		return (0);
	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (ft_strlen((char *)s2) > len)
		return (NULL);
	while (i < len && (s1[i] != '\0'))
	{
		if (s1[i] == s2[0])
		{
			if (ft_strncmp((char *)(s1 + i), (char *)s2, ft_strlen(s2)) == 0)
			{
				if (i + ft_strlen((char *)s2) > len)
					return (0);
				return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (0);
}
