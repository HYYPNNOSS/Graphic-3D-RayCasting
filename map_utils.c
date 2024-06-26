/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:20:48 by btaha             #+#    #+#             */
/*   Updated: 2023/01/24 00:49:51 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map(char *str, t_input *input, int fd)
{
	char	*str1;
	t_list	*lst;

	lst = ft_lstnew(str);
	while (1)
	{
		str1 = get_next_line(fd);
		if (!str1)
			break ;
		if (ft_search(str1, " 10NWSE") == ft_strlen(str1))
			ft_lstadd_back(&lst, ft_lstnew(str1));
		else
			return (1);
	}
	fill_map(lst, input);
	if (!input->map)
		return (1);
	return (0);
}

int	check_name(char *name)
{
	size_t	i;

	i = 0;
	while (name && i < (ft_strlen(name) - 4))
		name++;
	if (ft_strncmp(name, ".cub", 4))
		return (1);
	return (0);
}
