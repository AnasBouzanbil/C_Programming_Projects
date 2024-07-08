/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:58:01 by ceddibao          #+#    #+#             */
/*   Updated: 2023/05/15 17:03:04 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	get_player_pos(char **map, int flag, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || \
			map[i][j] == 'E' || map[i][j] == 'S')
			{
				data->vision = map[i][j];
				if (flag == 0)
					return (j);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	detect_colation(char **map, int py, int px, t_data *data)
{
	int	newx;
	int	newy;

	newx = px / (64 / MINIMAP_SCALE);
	newy = py / (64 / MINIMAP_SCALE);
	if (newy <= 0 || newx < 0)
		return (0);
	if (!map[newy] || !map[newy][newx] || \
	map[newy][newx] == '1' || map[newy][newx] == '\n')
		return (0);
	return (1);
}

double	turn_to_rad(double deg)
{
	return (deg * (PI / 180.0));
}

void	set_vision(t_data *data)
{
	if (data->vision == 'E')
		data->p_angle = 0;
	else if (data->vision == 'W')
		data->p_angle = 180;
	else if (data->vision == 'N')
		data->p_angle = 90;
	else if (data->vision == 'S')
		data->p_angle = 270;
}

void	ft_execution(t_all *all)
{
	all->data.map_width = ft_strlen(all->data.map[0]);
	all->data.map_height = get_map_height(all->data.map);
	all->data.p_x = get_player_pos(all->data.map, 0, \
	&all->data) * (16) + (16 / 2);
all->data.p_y = get_player_pos(all->data.map, 1, &all->data) * (16) + (16 / 2);
	all->data.fov = 60;
	set_vision(&all->data);
	all->data.p_speed = 20;
	all->data.p_rot_speed = 15;
	all->data.screen_width = 1200;
	all->data.screen_height = 1000;
	all->data.mlx_window = mlx_new_window(all->data.mlx_instance, \
	all->data.screen_width, \
	all->data.screen_height, "charaf windows");
	all->data.mlx_bgimage = mlx_new_image(all->data.mlx_instance, \
	all->data.screen_width, all->data.screen_height);
	all->data.mlx_bgimage_addr = mlx_get_data_addr(all->data.mlx_bgimage, \
	&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	all->data.j = 50;
	draw_pixels(&all->data);
	mlx_put_image_to_window(all->data.mlx_instance, \
	all->data.mlx_window, all->data.mlx_bgimage, 0, 0);
	mlx_hook(all->data.mlx_window, 2, 1L << 0, key_hook, all);
	mlx_hook(all->data.mlx_window, 17, 0L, close_window, NULL);
	mlx_loop(all->data.mlx_instance);
}
