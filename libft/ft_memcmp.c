/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:03:03 by btaha             #+#    #+#             */
/*   Updated: 2021/11/09 18:11:54 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t		i;
	const char	*ptr1;
	const char	*ptr2;
	int			value;

	value = 0;
	i = 0;
	ptr1 = (const char *) pointer1;
	ptr2 = (const char *) pointer2;
	while (!(value) && (i < size))
	{
		value = (unsigned char)ptr1[i] - (unsigned char)ptr2[i];
		i++;
	}
	return (value);
}
