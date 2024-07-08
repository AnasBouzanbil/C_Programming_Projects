/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceddibao <ceddibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:02:52 by ceddibao          #+#    #+#             */
/*   Updated: 2023/05/15 12:03:41 by ceddibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	do_put_for_y(t_data *data, unsigned int *toput)
{
	if (n_s(data) == 'S')
	{
		data->fill_x = data->inter_y * (float)data->so.text_width / 16;
		if (data->fill_x > data->so.text_width)
			data->fill_x %= data->so.text_width;
		data->fill_y = (int)((data->wall_start) * \
		data->so.text_height / data->wall_height);
		data->fill_offset = data->fill_y * data->so.text_line_lenght \
		+ data->fill_x * (data->so.bit_per_pixel / 8);
		*toput = *(unsigned int *)(data->so.text + data->fill_offset);
	}
	else
	{
		data->fill_x = data->inter_y * (float)data->no.text_width / 16;
		if (data->fill_x > data->no.text_width)
			data->fill_x %= data->no.text_width;
		data->fill_y = (int)((data->wall_start) * \
		data->no.text_height / data->wall_height);
		data->fill_offset = data->fill_y * data->no.text_line_lenght + \
		data->fill_x * (data->no.bit_per_pixel / 8);
		*toput = *(unsigned int *)(data->no.text + data->fill_offset);
	}
}

void	cast_rays(t_data *data)
{
	double	fst_ray;
	double	ray_end;

	data->start_x = 0;
	fst_ray = data->p_angle + (data->fov / 2);
	ray_end = fst_ray - data->fov;
	while (fst_ray > ray_end)
	{
		data->fstrayy = fst_ray;
		data->lstrayy = ray_end;
		data->df = drawline(data, data->p_x, data->p_y);
		data->df = data->df * cos(turn_to_rad(fst_ray - data->p_angle));
		draw_rect(data);
		fst_ray = fst_ray - (60 / data->screen_width);
	}
}

void	do_draw(t_data *data, int i, int cstart_y, int end_y)
{
	while (i < cstart_y)
	{
		my_mlx_pixel_put(data, data->start_x, data->c_colour, 1);
		data->start_y++;
		i++;
	}
	data->start_y = cstart_y;
	while (end_y > data->start_y)
	{
		my_mlx_pixel_put(data, data->start_x, 0xFFFFFF, 0);
		data->start_y++;
		data->wall_start++;
	}
	data->start_y = end_y;
	while (data->screen_height > data->start_y)
	{
		my_mlx_pixel_put(data, data->start_x, data->f_colour, 1);
		data->start_y++;
	}
}
