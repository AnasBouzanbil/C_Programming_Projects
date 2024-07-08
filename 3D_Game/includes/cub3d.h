/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:20:28 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 16:15:10 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <strings.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_temp
{
	int	elements;
	int	i;
	int	x;
	int	a;
	int	ok;
}t_temp;
typedef struct s_S
{
	int	x;
	int	space;
	int	i;
	int	a;
	int	player;
	int	wall;
}t_l;
typedef struct s_ray
{
	double	length;
	double	player_pos;
	double	*rays;
}t_ray;

typedef struct s_map
{
	char	**map;
	char	**temp;
	char	**use;
	char	*name;
	int		big_size;
	int		row_number;
	char	**d;
}t_map;

typedef struct s_emelemnts
{
	char	*ea;
	char	*so;
	char	*we;
	char	*no;
	char	*f_temp;
	char	*c_temp;
	int		ctemp1;
	int		ctemp2;
	int		ctemp3;
	int		ftemp1;
	int		ftemp2;
	int		ftemp3;
}t_elem;

typedef struct s_text_colo
{
	void	*ea;
	void	*so;
	void	*we;
	void	*no;
	int		f;
	int		c;
}t_struct;

typedef struct textuers_info{
	int		bit_per_pixel;
	int		text_line_lenght;
	int		text_width;
	int		text_height;
	int		text_endian;
	char	*text;
}t_info;
typedef struct s_data
{
	t_info	we;
	t_info	so;
	t_info	no;
	t_info	ea;
	double	fstrayy;
	double	lstrayy;
	void	*mlx_instance;
	void	*mlx_window;
	void	*mlx_bgimage;
	char	*mlx_bgimage_addr;
	int		text_height;
	double	fov;
	double	plane_dim_x;
	double	plane_dim_y;
	double	plane_center_dim;
	double	dtp;
	double	dbr;
	int		i;
	int		j;
	double	p_x;
	double	p_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_width;
	int		map_height;
	double	screen_width;
	double	screen_height;
	char	**map;
	double	p_angle;
	double	p_speed;
	double	p_rot_speed;
	double	df;
	double	color;
	double	wall_height;
	double	middle_y;
	double	start_x;
	double	inter_x;
	double	inter_y;
	char	vision;
	char	fin_9ass;
	double	fov_m;
	int		wall_start;
	int		start_y;
	t_ray	*ray;
	int		fill_y;
	int		fill_offset;
	int		fill_x;
	int		f_colour;
	int		c_colour;
}t_data;

typedef struct s_all
{
	t_data		data;
	t_struct	tool;
	t_map		map;
	t_elem		*elem;
}t_all;
# define PI 3.10
# define MINIMAP_SCALE 4
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define WALL_HEIGHT 50
# define WALL_WIDTH 8

void	my_mlx_pixel_put(t_data *data, int x, int color, int flag);
int		get_map_height(char **map);
int		ft_strlen(char *s);
int		get_player_pos(char **map, int flag, t_data *data);
int		detect_colation(char **map, int x, int y, t_data *data);
double	turn_to_rad(double deg);
double	drawline(t_data *data, double x1, double y1);
void	cast_rays(t_data *data);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	draw_pixels(t_data *data);
void	set_vision(t_data *data);
void	ft_execution(t_all *all);
void	ft_parsing(t_all *all, char *av);
int		key_hook(int keycode, t_all *all);
void	do_put_for_x(t_data *data, unsigned int *toput);
void	do_put_for_y(t_data *data, unsigned int *toput);
char	n_s(t_data *data);
char	e_w(t_data *data);
void	do_put_for_y(t_data *data, unsigned int *toput);
void	draw_rect(t_data *data);
char	**ft_split(char *str, char cut);
int		ft_atoi(char *s);
int		all_is_space(char *s);
void	init(char **use, t_all *all);
void	ft_put_map(char *key, char *name, int *x);
void	put_it(t_all *all, char *name);
char	*return_elements(char *str);
void	read_map(t_all *all);
void	set_it(t_all *all, char *c, char *f);
void	check_map(char **map);
void	handle_rgb(t_all *all);
size_t	ft_strlcpy(char *dest, char *str, size_t size);
void	count_str(char **str);
void	ft_help_check_ele(char **str, t_l *l);
void	initilaized(t_all *all, char **f, char **c);
int		close_window(void);
void	do_draw(t_data *data, int i, int cstart_y, int end_y);
void	change_angle(int keycode, t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
int		move_down(t_data *data);
int		move_up(t_data *data);
void	free_str(char **str);
void	ft_help_put_them_in_the_place(t_all *all, t_temp *t);
#endif