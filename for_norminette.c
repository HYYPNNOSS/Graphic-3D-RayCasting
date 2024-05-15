/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_norminette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:17:41 by btaha             #+#    #+#             */
/*   Updated: 2023/01/24 00:50:00 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_between_lines(char **map, int x, int y)
{
	if (map[x][y] && !(map[x][y] == ' ' || map[x][y] == '1')
		&& (map[x][y - 1] == ' ' || map[x][y + 1] == ' '
		|| map[x - 1][y] == ' ' || map[x + 1][y] == ' '
		|| map[x][y + 1] == '\0' || map[x + 1][y] == '\0'
		|| map[x - 1][y] == '\0'))
		return (1);
	else
		return (0);
}

void	print_error(void)
{
	ft_putendl_fd("Error invalid map", 2);
}

void	init_input(t_input	*input)
{
	input->n = NULL;
	input->s = NULL;
	input->e = NULL;
	input->w = NULL;
	input->floor = NULL;
	input->ceil = NULL;
	input->map = NULL;
}

void	overboard_checker(float hit_x, float hit_y, t_data *data, char c)
{
	if (c == 'h')
	{
		if (hit_x > (data->num_cols * TILE_SIZE)
			|| hit_y > (data->num_rows * TILE_SIZE))
		{
			data->ray->wall_hit_horizantalx = data->num_cols * TILE_SIZE;
			data->ray->wall_hit_horizantaly = data->num_rows * TILE_SIZE;
		}
	}
	else
	{
		if (hit_x > (data->num_cols * TILE_SIZE)
			|| hit_y > (data->num_rows * TILE_SIZE))
		{
			data->ray->wall_hit_verticalx = (data->num_cols * TILE_SIZE);
			data->ray->wall_hit_verticaly = (data->num_rows * TILE_SIZE);
		}
	}
}
