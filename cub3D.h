/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:27:44 by hel-hich          #+#    #+#             */
/*   Updated: 2023/01/24 00:45:05 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <mlx.h>
# include <math.h>

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MINI_MAP_WIDTH 200
# define MINI_MAP_HEIGHT 200
# define NUM_RAYS WINDOW_WIDTH
# define TILE_SIZE 32

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_input
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	int		*floor;
	int		*ceil;
	char	**map;
}	t_input;

typedef struct s_player
{
	double	x;
	double	y;
	double	rotation_angles;
	double	walk_speed;
	double	turn_speed;
}			t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_horizantalx;
	float	wall_hit_horizantaly;
	float	wall_hit_verticalx;
	float	wall_hit_verticaly;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	char	wall_hit_content;
}			t_ray;

typedef struct s_texturs
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}			t_texturs;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			num_rows;
	int			num_cols;
	double		fov;
	t_texturs	*texture[4];
	t_ray		*ray;
	t_input		*input;
	t_keys		*key;
	t_player	*player;
	t_image		*image;
}			t_data;

int		*fill_rgb(char *str);
void	print_error(void);
int		check_between_lines(char **map, int x, int y);
void	init_input(t_input	*input);
char	**rgb_checker(char *str);
int		check_name(char *name);
int		texture_checker(char *str, t_input *input);
int		line_checker(char *str, t_input *input, int fd);
int		input_filler(int fd, t_input *input);
char	*fill_line(char const *s, int len);
int		color_checker(char *str, t_input *input);
void	free_input(t_input *input);
int		check_map(char *str, t_input *input, int fd);
int		check_empty(t_input *input);
void	fill_map(t_list *lst, t_input *input);
int		longest_line(t_list *lst);
void	fill_rc(t_data *data);

int		rgb_color(int r, int g, int b);
int		set_player(t_data *data, char c, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		setup(t_data *data);
int		game_launcher(t_data *data);
int		data_init(t_data *data, t_input *input);
void	free_data(t_data *data);
int		keypress_handle(int keynum, t_data *data);
int		keyrelease_handle(int keynum, t_data *data);
int		player_movement(t_data *data);
void	floor_ceil(t_data *data);
void	initialize_ray(t_ray *ray, float angle);
float	solve_angle(float angle);
int		has_wall_at(t_data *data, int x, int y, char c);
void	first_xy_wallhit(t_data *data, float *hit_x, float *hit_y, char c);
void	next_step_xy(t_data *data, float *step_x, float *step_y, char c);
void	intersection_h(t_data *data);
void	intersection_v(t_data *data);
void	distance(t_data *data);
void	projection_3d(t_data *data, int i);
int		texture_img(t_data *data);
void	free_mlx(t_data *data);
void	overboard_checker(float hit_x, float hit_y, t_data *data, char c);

#endif
