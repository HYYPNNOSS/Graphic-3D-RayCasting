/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:27:52 by hel-hich          #+#    #+#             */
/*   Updated: 2023/01/24 00:45:05 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	esc_key(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	raycasting(t_data *data)
{
	intersection_h(data);
	intersection_v(data);
	distance(data);
}

void	angles_ray_caster(t_data *data)
{
	int	i;

	i = 0;
	data->ray->ray_angle = data->player->rotation_angles - (data->fov / 2);
	while (i < NUM_RAYS)
	{
		initialize_ray(data->ray, solve_angle(data->ray->ray_angle));
		raycasting(data);
		projection_3d(data, i);
		data->ray->ray_angle += data->fov / NUM_RAYS;
		i++;
	}
}

int	game_launcher(t_data *data)
{
	floor_ceil(data);
	angles_ray_caster(data);
	player_movement(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_input	input;
	t_data	data;
	int		file;

	if (ac != 2)
		return (ft_putendl_fd("Error invalid argument", 2), 1);
	file = open(av[1], O_RDWR);
	if (file == -1)
		return (ft_putendl_fd("Error can't open map", 2), 1);
	if (check_name(av[1]) == 1)
		return (ft_putendl_fd("Error invalid map name", 2), 1);
	init_input(&input);
	if (input_filler(file, &input) == 1)
		return (close(file), free_input(&input), 1);
	close(file);
	if (data_init(&data, &input) == 1)
		return (free_data(&data), 1);
	mlx_hook(data.win, 02, 1L << 0, &keypress_handle, &data);
	mlx_hook(data.win, 03, 2L << 0, &keyrelease_handle, &data);
	mlx_hook(data.win, 17, 2, esc_key, &data);
	mlx_loop_hook(data.mlx, game_launcher, &data);
	mlx_loop(data.mlx);
	return (free_data(&data), 0);
}
