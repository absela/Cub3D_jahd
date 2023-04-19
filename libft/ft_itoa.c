/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:05:08 by abelahce          #+#    #+#             */
/*   Updated: 2021/11/28 15:52:28 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	cpystr(long long n, int k, char *str)
{
	while (n != 0)
	{
		str[k] = 48 + (n % 10);
		n = n / 10;
		k--;
	}
}

static	int	checknum(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	i;
	int		k;
	char	*str;

	k = checknum(n);
	if (k == 0)
	{
		str = (char *)malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(k * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[k] = '\0';
	i = n;
	if (i < 0)
	{
		i = i * -1;
		str[0] = '-';
	}
	cpystr(i, k - 1, str);
	return (str);
}
