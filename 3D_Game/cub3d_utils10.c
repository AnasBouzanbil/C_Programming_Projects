/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:27 by ceddibao          #+#    #+#             */
/*   Updated: 2023/05/15 16:14:52 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	change_angle(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->p_angle += 5;
		if (data->p_angle > 360)
			data->p_angle = data->p_angle - 360;
		draw_pixels(data);
	}
	else if (keycode == 124)
	{
		data->p_angle -= 5;
		if (data->p_angle < 0)
			data->p_angle = 360 + data->p_angle;
		draw_pixels(data);
	}
}

int	move_up(t_data *data)
{
	double	player_cos;
	double	player_sin;

	player_cos = (cos(turn_to_rad(data->p_angle)) \
	* data->p_speed) / MINIMAP_SCALE;
	player_sin = (sin(turn_to_rad(data->p_angle)) \
	* data->p_speed) / MINIMAP_SCALE;
	data->p_x += player_cos;
	data->p_y -= player_sin;
	if (detect_colation(data->map, data->p_y, \
	data->p_x, data) == 0)
	{
		data->p_x -= player_cos;
		data->p_y += player_sin;
		return (0);
	}
	draw_pixels(data);
	return (0);
}

int	move_down(t_data *data)
{
	double	player_cos;
	double	player_sin;

	player_cos = (cos(turn_to_rad(data->p_angle)) \
	* data->p_speed) / MINIMAP_SCALE;
	player_sin = (sin(turn_to_rad(data->p_angle)) \
	* data->p_speed) / MINIMAP_SCALE;
	data->p_x -= player_cos;
	data->p_y += player_sin;
	if (detect_colation(data->map, data->p_y, \
	data->p_x, data) == 0)
	{
		data->p_x += player_cos;
		data->p_y -= player_sin;
		return (0);
	}
	draw_pixels(data);
	return (0);
}

int	move_left(t_data *data)
{
	double	player_cos;
	double	player_sin;

	player_cos = (cos(turn_to_rad(data->p_angle + 90)) \
	* data->p_speed) / MINIMAP_SCALE;
	player_sin = (sin(turn_to_rad(data->p_angle + 90)) \
	* data->p_speed) / MINIMAP_SCALE;
	data->p_x += player_cos;
	data->p_y -= player_sin;
	if (detect_colation(data->map, data->p_y, \
	data->p_x, data) == 0)
	{
		data->p_x -= player_cos;
		data->p_y += player_sin;
		return (0);
	}
	draw_pixels(data);
	return (0);
}

int	move_right(t_data *data)
{
	double	player_cos;
	double	player_sin;

	player_cos = (cos(turn_to_rad(data->p_angle - 90)) \
	* data->p_speed) / MINIMAP_SCALE;
	player_sin = (sin(turn_to_rad(data->p_angle - 90)) \
	* data->p_speed) / MINIMAP_SCALE;
	data->p_x += player_cos;
	data->p_y -= player_sin;
	if (detect_colation(data->map, data->p_y, \
	data->p_x, data) == 0)
	{
		data->p_x -= player_cos;
		data->p_y += player_sin;
		return (0);
	}
	draw_pixels(data);
	return (0);
}
