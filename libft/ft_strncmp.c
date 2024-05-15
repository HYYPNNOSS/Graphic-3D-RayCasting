/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:24:44 by btaha             #+#    #+#             */
/*   Updated: 2021/11/21 16:24:46 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		value;
	size_t	i;

	value = 0;
	i = 0;
	while ((i < n) && (!value) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		value = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (value);
}
