/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:28:39 by hel-hich          #+#    #+#             */
/*   Updated: 2023/01/24 00:49:06 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_ceil(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	while (width < WINDOW_WIDTH)
	{
		height = 0;
		while (height <= (WINDOW_HEIGHT / 2))
		{
			my_mlx_pixel_put(data, width, height,
				rgb_color(data->input->ceil[0],
					data->input->ceil[1],
					data->input->ceil[2]));
			height++;
		}
		while (height < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put(data, width, height,
				rgb_color(data->input->floor[0],
					data->input->floor[1],
					data->input->floor[2]));
			height++;
		}
		width++;
	}
}

t_texturs	*get_texture(t_data *data)
{
	if (!data->ray->was_hit_vertical && data->ray->is_ray_facing_up)
		return (data->texture[0]);
	if (!data->ray->was_hit_vertical && !data->ray->is_ray_facing_up)
		return (data->texture[1]);
	if (data->ray->was_hit_vertical && data->ray->is_ray_facing_right)
		return (data->texture[2]);
	else
		return (data->texture[3]);
}

int	has_wall_at(t_data *data, int col, int row, char chr)
{
	if (row >= data->num_rows || col >= data->num_cols
		|| col <= 0 || row <= 0)
		return (1);
	if (data->ray->is_ray_facing_right && chr == 'v' )
		if (data->input->map[row][col] == '1')
			return (1);
	if (data->ray->is_ray_facing_up && chr == 'h')
		if (data->input->map[row - 1][col] == '1')
			return (1);
	if (!data->ray->is_ray_facing_right && chr == 'v' )
		if (data->input->map[row][col - 1] == '1')
			return (1);
	if (!data->ray->is_ray_facing_up && chr == 'h')
		if (data->input->map[row][col] == '1')
			return (1);
	return (0);
}

static void	draw_texture(t_data *data, int x_y[2], int wall_bottom,
						double wall_height)
{
	t_texturs	*txt;
	int			txt_x;
	int			txt_y;
	int			offset;

	txt = get_texture(data);
	if (data->ray->was_hit_vertical)
		txt_x = fmod(data->ray->wall_hit_verticaly, TILE_SIZE)
			* (txt->width / TILE_SIZE);
	else
		txt_x = fmod(data->ray->wall_hit_horizantalx, TILE_SIZE)
			* (txt->width / TILE_SIZE);
	while (x_y[1] < wall_bottom)
	{
		offset = x_y[1] + (wall_height - WINDOW_HEIGHT) / 2;
		txt_y = offset * (txt->height / wall_height);
		my_mlx_pixel_put(data, x_y[0], x_y[1],
			((int *)txt->addr)[((txt->width * txt_y) + txt_x)]);
		x_y[1]++;
	}
}

void	projection_3d(t_data *data, int i)
{
	double	wallheight_projection;
	int		top_pixel;
	int		bottom_pixel;
	int		cord[2];

	cord[0] = i;
	wallheight_projection = (TILE_SIZE / (data->ray->distance
				* cos(data->ray->ray_angle - data->player->rotation_angles)))
		* ((WINDOW_WIDTH / 2) / tan(data->fov / 2));
	top_pixel = (int)((WINDOW_HEIGHT / 2) - (wallheight_projection / 2));
	bottom_pixel = (int)((WINDOW_HEIGHT / 2) + (wallheight_projection / 2));
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > WINDOW_HEIGHT)
		bottom_pixel = WINDOW_HEIGHT;
	cord[1] = top_pixel;
	draw_texture(data, cord, bottom_pixel, wallheight_projection);
}
