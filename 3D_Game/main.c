/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:23:33 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 16:15:02 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	drawline(t_data *data, double x1, double y1)
{
	double	temp_x;
	double	temp_y;

	while (1)
	{
		temp_x = x1;
		temp_y = y1;
		x1 += cos(turn_to_rad(data->fstrayy)) / 16;
		if (detect_colation(data->map, y1, x1, data) == 0)
		{
			data->inter_y = y1;
			data->inter_x = x1;
			data->fin_9ass = 'x';
			return (sqrt(pow(x1 - data->p_x, 2) + pow(y1 - data->p_y, 2)));
		}
		y1 -= sin(turn_to_rad(data->fstrayy)) / 16;
		if (detect_colation(data->map, y1, x1, data) == 0)
		{
			data->inter_y = x1;
			data->inter_x = y1;
			data->fin_9ass = 'y';
			return (sqrt(pow(x1 - data->p_x, 2) + pow(y1 - data->p_y, 2)));
		}
	}
	return (-1);
}

void	draw_pixels(t_data *data)
{
	mlx_clear_window(data-> mlx_instance, data->mlx_window);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx_instance, \
	data->mlx_window, data->mlx_bgimage, 0, 0);
}

int	key_hook(int keycode, t_all *all)
{
	t_data	*data;
	double	player_cos;
	double	player_sin;

	data = &all->data;
	mlx_destroy_image(data->mlx_instance, data->mlx_bgimage);
	data->mlx_bgimage = mlx_new_image(data->mlx_instance, \
	data->screen_width, data->screen_height);
	data->mlx_bgimage_addr = mlx_get_data_addr(data->mlx_bgimage, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	if (keycode == 53)
		exit(0);
	change_angle(keycode, data);
	if (keycode == 13)
		return (move_up(data));
	else if (keycode == 1)
		return (move_down(data));
	else if (keycode == 0)
		return (move_left(data));
	else if (keycode == 2)
		return (move_right(data));
	return (0);
}

int	close_window(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac == 2)
	{
		ft_parsing(&all, av[1]);
		ft_execution(&all);
		ac = 0;
		return (ac);
	}
	return (1);
}
