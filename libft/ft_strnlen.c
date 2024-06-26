/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:48:20 by btaha             #+#    #+#             */
/*   Updated: 2023/01/23 02:48:21 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnlen(const char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!str[i])
			return (i);
		i++;
	}
	return (i);
}
