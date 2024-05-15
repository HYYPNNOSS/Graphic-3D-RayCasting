/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:17:48 by btaha             #+#    #+#             */
/*   Updated: 2023/01/24 00:32:47 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*fill_rgb(char *str)
{
	int		*i_rgb;
	char	**c_rgb;
	int		i;

	i = 0;
	c_rgb = rgb_checker(str);
	if (!c_rgb)
		return (NULL);
	i_rgb = malloc(sizeof(int) * 3);
	if (!i_rgb)
		return (free_tab(c_rgb), NULL);
	while (c_rgb[i])
	{
		i_rgb[i] = ft_atoi(c_rgb[i]);
		if (i_rgb[i] < 0 || i_rgb[i] > 255)
			return (free_tab(c_rgb), free(i_rgb), NULL);
		i++;
	}
	return (free_tab(c_rgb), i_rgb);
}

void	fill_map(t_list *lst, t_input *input)
{
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = lst;
	input->map = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!input->map)
		return ;
	len = longest_line(lst);
	while (lst)
	{
		input->map[i] = fill_line(lst->content, len);
		i++;
		lst = lst->next;
	}
	ft_lstclear(&tmp, free);
}

int	check_p(char **map)
{
	int	x;
	int	y;
	int	number_of_players;

	if (!map)
		return (1);
	x = 0;
	number_of_players = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'E' || map[x][y] == 'W')
				number_of_players++;
			y++;
		}
		x++;
	}
	if (number_of_players != 1)
		return (1);
	return (0);
}

int	is_valid(char **map, int x)
{
	int		y;

	while (map[x])
	{
		y = 0;
		if (map[x + 1] == '\0'
			|| ft_search(map[x + 1], " ") == ft_strlen(map[x]))
		{
			if ((ft_search(map[x], " 1") == ft_strlen(map[x])))
				return (0);
			return (1);
		}
		if (!ft_strchr(map[x], '1') || map[x][y] == '\0'
				|| (map[x][y] != ' ' && map[x][y] != '1'))
			return (1);
		while (map[x][y])
		{
			if (check_between_lines(map, x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	input_filler(int fd, t_input *input)
{
	char	*str;
	t_list	*lst;

	lst = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (line_checker(str, input, fd))
			return (free(str), print_error(), 1);
	}
	if (!input->map || ((get_len_row(input->map) < 3)))
		return (print_error(), 1);
	if (is_valid(input->map, 1) || check_p(input->map))
		return (print_error(), 1);
	return (0);
}
