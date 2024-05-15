/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:29:41 by btaha             #+#    #+#             */
/*   Updated: 2021/11/19 18:24:29 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (1);
	if (len < 0)
	{
		len = len * -1;
		i++;
	}
	while (len != 0)
	{
		len = len / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = size(num);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		num = num * (-1);
		str[i] = '-';
	}
	i = len - 1;
	while (i >= 0 && !(n < 0 && i == 0))
	{
		str[i] = (num % 10) + 48;
		i--;
		num = num / 10;
	}
	return (str);
}
