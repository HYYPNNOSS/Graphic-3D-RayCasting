/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:28:14 by hel-hich          #+#    #+#             */
/*   Updated: 2023/01/24 00:12:02 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall_checker(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (data->input->map[j][i] == '1' || data->input->map[j][i] == ' '
		|| data->input->map[j][i] == '\0')
		return (0);
	return (1);
}

static int	ultimate_check_wall(t_data *data, double x, double y)
{
	int	i;
	int	j;
	int	k;
	int	h;

	i = floor((x + 2) / TILE_SIZE);
	j = floor((y + 2) / TILE_SIZE);
	k = floor((x - 2) / TILE_SIZE);
	h = floor((y - 2) / TILE_SIZE);
	if (data->input->map[j][i] == '1' || data->input->map[j][i] == ' '
		|| data->input->map[j][i] == '\0' || data->input->map[h][k] == '1'
			|| data->input->map[h][k] == ' ' || data->input->map[h][k] == '\0')
		return (0);
	if (data->input->map[j][k] == '1' || data->input->map[j][k] == ' '
		|| data->input->map[j][k] == '\0' || data->input->map[h][i] == '1'
			|| data->input->map[h][i] == ' ' || data->input->map[h][i] == '\0')
		return (0);
	return (1);
}

void	next_position(t_data *data, double *x, double *y, int dir)
{
	if (data->key->d || data->key->a)
	{
		*x += cos(data->player->rotation_angles + (dir * M_PI_2))
			* data->player->walk_speed;
		*y -= sin(data->player->rotation_angles + (dir * M_PI_2))
			* data->player->walk_speed;
	}
	if (data->key->s || data->key->w)
	{
		*x += cos(data->player->rotation_angles)
			* dir * data->player->walk_speed;
		*y -= sin(data->player->rotation_angles)
			* dir * data->player->walk_speed;
	}
}

int	player_movement(t_data *data)
{
	double	nextx;
	double	nexty;

	nextx = data->player->x;
	nexty = data->player->y;
	if (data->key->w)
		next_position(data, &nextx, &nexty, 1);
	if (data->key->s)
		next_position(data, &nextx, &nexty, -1);
	if (data->key->d)
		next_position(data, &nextx, &nexty, 1);
	if (data->key->a)
		next_position(data, &nextx, &nexty, -1);
	if (data->key->right)
		data->player->rotation_angles += data->player->turn_speed;
	if (data->key->left)
		data->player->rotation_angles -= data->player->turn_speed;
	if (ultimate_check_wall(data, nextx, nexty))
	{
		data->player->x = nextx;
		data->player->y = nexty;
	}
	return (0);
}
