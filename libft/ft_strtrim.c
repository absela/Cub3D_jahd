/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 07:59:58 by abelahce          #+#    #+#             */
/*   Updated: 2023/03/30 20:15:12 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	checkchar(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] && checkchar(set, s1[j]))
		j++;
	k = ft_strlen(s1) - 1;
	while (k >= j && checkchar(set, s1[k]))
		k--;
	str = (char *)malloc(k - j + 2);
	if (!str)
		return (NULL);
	while (j <= k)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (free((void *)s1), str);
}
