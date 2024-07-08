/* ************************************************************************** */
/*																			  */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:41:08 by ceddibao          #+#    #+#             */
/*   Updated: 2023/05/14 19:03:30 by abouzanb         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/get_next_line.h"
  
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	n_s(t_data *data)
{
	if (data->fin_9ass == 'y')
	{
		if (data->p_y > data->inter_x)
			return ('N');
		return ('S');
	}
	return (0);
}

char	e_w(t_data *data)
{
	if (data->fin_9ass == 'x')
	{
		if (data->p_x > data->inter_x)
			return ('W');
		return ('E');
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int color, int flag)
{
	char			*dst;
	unsigned int	toput;

	if (x < 0 || x >= data->screen_width || data->start_y < \
	0 || data->start_y >= data->screen_height)
		return ;
	dst = data->mlx_bgimage_addr + (data->start_y * \
	data->line_length + x * (data->bits_per_pixel / 8));
	if (data->fin_9ass == 'x')
		do_put_for_x(data, &toput);
	else
		do_put_for_y(data, &toput);
	if (flag == 0)
		*(unsigned int *)dst = toput;
	else if (flag == 1)
		*(unsigned int *)dst = color;
}

void	draw_rect(t_data *data)
{
	int		steps;
	int		cstart_y;
	double	end_y;
	int		i;

	data->middle_y = round(data->screen_height / 2);
	data->wall_height = round((64 / data->df) * 200);
	i = 0;
	data->start_y = round(data->middle_y - (data->wall_height / 2));
	end_y = round(data->start_y + data->wall_height);
	cstart_y = data->start_y;
	steps = data->text_height / data->wall_height;
	data->wall_start = 0;
	data->start_y = 0;
	do_draw(data, i, cstart_y, end_y);
	data->start_x++;
}
