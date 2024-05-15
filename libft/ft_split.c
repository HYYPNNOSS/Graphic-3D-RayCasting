/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:00:18 by btaha             #+#    #+#             */
/*   Updated: 2021/11/22 02:22:41 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_arrays(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
			num++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (num);
}

static int	free_arr(char *str, char **str0)
{
	int	i;

	if (!str)
	{
		i = 0;
		while (str0[i])
		{
			free(str0[i]);
			i++;
		}
		free(str0);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;
	int		index;
	int		arrays;

	if (!s)
		return (NULL);
	arrays = count_arrays(s, c);
	index = 0;
	str = ft_calloc((arrays + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (*s && index < arrays)
	{
		while (*s == c && *s)
			s++;
		len = 0;
		while (*s != c && *s && ++len)
			s++;
		str[index] = ft_substr(s - len, 0, len);
		if (free_arr(str[index], str))
			return (NULL);
		index++;
	}
	return (str);
}
