/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:05:47 by btaha             #+#    #+#             */
/*   Updated: 2021/11/21 20:40:56 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len )
{
	size_t	i;
	char	*strdst;
	char	*strsrc;

	i = 0;
	strdst = (char *)dst;
	strsrc = (char *)src;
	if (!strdst && !strsrc)
		return (NULL);
	if (src < dst)
	{
		while (len--)
		{
			strdst[len] = strsrc[len];
		}
	}
	else
	{
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	return (strdst);
}
