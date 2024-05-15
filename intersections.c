/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectionxy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:27:28 by hel-hich          #+#    #+#             */
/*   Updated: 2023/01/23 23:40:50 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	first_xy_wallhit(t_data *data, float *hit_x, float *hit_y, char c)
{
	if (c == 'x')
	{
		*hit_y = floor(data->player->y / TILE_SIZE) * TILE_SIZE;
		if (!data->ray->is_ray_facing_up)
			*hit_y += TILE_SIZE;
		*hit_x = data->player->x - (*hit_y - data->player->y)
			/ tan(data->ray->ray_angle);
	}
	else
	{
		*hit_x = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
		if (data->ray->is_ray_facing_right)
			*hit_x += TILE_SIZE;
		*hit_y = data->player->y
			- ((*hit_x - data->player->x) * tan(data->ray->ray_angle));
	}
}

void	next_step_xy(t_data *data, float *step_x, float *step_y, char c)
{
	if (c == 'x')
	{
		*step_y = TILE_SIZE;
		if (data->ray->is_ray_facing_up)
			*step_y *= -1;
		*step_x = TILE_SIZE / tan(data->ray->ray_angle);
		if ((*step_x > 0 && !data->ray->is_ray_facing_right)
			|| (*step_x < 0 && data->ray->is_ray_facing_right))
			*step_x *= -1;
	}
	else
	{
		*step_x = TILE_SIZE;
		if (!data->ray->is_ray_facing_right)
			*step_x *= -1;
		*step_y = TILE_SIZE * tan(data->ray->ray_angle);
		if ((*step_y > 0 && data->ray->is_ray_facing_up)
			|| (*step_y < 0 && !data->ray->is_ray_facing_up))
			*step_y *= -1 ;
	}
}

void	intersection_h(t_data *data)
{
	float	step_x;
	float	step_y;
	float	hit_x;
	float	hit_y;

	first_xy_wallhit(data, &hit_x, &hit_y, 'x');
	next_step_xy(data, &step_x, &step_y, 'x');
	while (hit_x >= 0 && hit_y >= 0
		&& hit_x <= (data->num_cols * TILE_SIZE)
		&& hit_y <= (data->num_rows * TILE_SIZE))
	{
		if (has_wall_at(data, (int)hit_x / TILE_SIZE,
				(int)hit_y / TILE_SIZE, 'h'))
		{
			data->ray->wall_hit_horizantalx = hit_x;
			data->ray->wall_hit_horizantaly = hit_y;
			break ;
		}
		hit_x += step_x;
		hit_y += step_y;
	}
	overboard_checker(hit_x, hit_y, data, 'h');
}

void	intersection_v(t_data *data)
{
	float	step_x;
	float	step_y;
	float	hit_x;
	float	hit_y;

	first_xy_wallhit(data, &hit_x, &hit_y, 'y');
	next_step_xy(data, &step_x, &step_y, 'y');
	while (hit_x >= 0 && hit_y >= 0
		&& hit_x <= (data->num_cols * TILE_SIZE)
		&& hit_y <= (data->num_rows * TILE_SIZE))
	{
		if (has_wall_at(data, (int)hit_x / TILE_SIZE,
				(int)hit_y / TILE_SIZE, 'v'))
		{
			data->ray->wall_hit_verticalx = hit_x;
			data->ray->wall_hit_verticaly = hit_y;
			break ;
		}
		hit_x += step_x;
		hit_y += step_y;
	}
	overboard_checker(hit_x, hit_y, data, 'v');
}

void	distance(t_data *data)
{
	float	horz_dst;
	float	vert_dst;

	horz_dst = sqrt(pow(data->ray->wall_hit_horizantalx - data->player->x, 2)
			+ pow(data->ray->wall_hit_horizantaly - data->player->y, 2));
	vert_dst = sqrt(pow(data->ray->wall_hit_verticalx - data->player->x, 2)
			+ pow(data->ray->wall_hit_verticaly - data->player->y, 2));
	if (horz_dst < vert_dst)
	{
		data->ray->distance = horz_dst;
		data->ray->was_hit_vertical = 0;
	}
	else
	{
		data->ray->distance = vert_dst;
		data->ray->was_hit_vertical = 1;
	}
}
