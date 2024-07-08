/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:57:59 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 15:46:05 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	put_them_in_the_place(t_all *all)
{
	t_temp	t;

	t.ok = 0;
	t.x = 0;
	t.a = 0;
	t.elements = 0;
	all->elem = calloc(sizeof(t_elem), 1);
	all->map.use = calloc(sizeof(char *) * (1 + all->map.row_number), 1);
	all->map.use[all->map.row_number] = NULL;
	init(all->map.use, all);
	t.i = 0;
	while (all->map.map[t.i])
		ft_help_put_them_in_the_place(all, &t);
	free(all->map.use[t.a]);
	all->map.use[t.a] = NULL;
	if (!all->elem->ea || !all->elem->we || !all->elem->c_temp \
	||!all->elem->f_temp ||!all->elem->no ||!all->elem->so)
		exit(write(2, "Error\nSome elements of the map is not valid\nOr \
they are not puted in their right place\nPleasee make sure the \
everything is in its place\n", 137));
}

void	check_textures(t_all *all)
{
	all->data.mlx_instance = mlx_init();
	all->tool.ea = mlx_xpm_file_to_image(all->data.mlx_instance, \
	all->elem->ea, &all->data.ea.text_width, &all->data.ea.text_height);
	all->tool.no = mlx_xpm_file_to_image(all->data.mlx_instance, all->elem->no, \
	&all->data.no.text_width, &all->data.no.text_height);
	all->tool.we = mlx_xpm_file_to_image(all->data.mlx_instance, all->elem->we, \
	&all->data.we.text_width, &all->data.we.text_height);
	all->tool.so = mlx_xpm_file_to_image(all->data.mlx_instance, all->elem->so, \
	&all->data.so.text_width, &all->data.so.text_height);
	if (!all->tool.ea || !all->tool.no || !all->tool.we || !all->tool.so)
		exit(write(2, "Error\nOops! Something does not wotk as expected\nMaybe \
the texteurs are not valid or they are not exis\nOr their contant is not \
correct\nPlease make sure that everyhting is correct\nThank you\n", 189));
	all->data.ea.text = mlx_get_data_addr(\
	all->tool.ea, &all->data.ea.bit_per_pixel, \
	&all->data.ea.text_line_lenght, &all->data.ea.text_endian);
all->data.so.text = mlx_get_data_addr(all->tool.so, &all->data.so.bit_per_pixel \
, &all->data.so.text_line_lenght, &all->data.so.text_endian);
	all->data.no.text = mlx_get_data_addr(\
	all->tool.no, &all->data.no.bit_per_pixel, \
	&all->data.no.text_line_lenght, &all->data.no.text_endian);
	all->data.we.text = mlx_get_data_addr(\
	all->tool.we, &all->data.we.bit_per_pixel, \
	&all->data.we.text_line_lenght, &all->data.we.text_endian);
	if (!all->data.ea.text || !all->data.so.text \
	| !all->data.no.text | !all->data.we.text)
		exit(write(2, " Error\nOpps something does not work as expacted\n", 48));
}

void	ft_help_check_ele(char **str, t_l *l)
{
	while (str[l->a])
	{	
		l->i = 0;
		while (str[l->a][l->i])
		{
			if (str[l->a][l->i] == 'N' || str[l->a][l->i] == 'S' \
			|| str[l->a][l->i] == 'W' || str[l->a][l->i] == 'E')
				l->player++;
			else if (str[l->a][l->i] == '1')
				l->wall++;
			else if (str[l->a][l->i] == '0')
					l->space++;
			else if (str[l->a][l->i] == ' ' || str[l->a][l->i] == '\n')
			{
				l->i++;
				continue ;
			}
			else
				exit(write(2, "Error\nA character is not valid\n", 32));
			l->i++;
		}
		l->a++;
	}
}

void	is_they_valid(t_all *all)
{
	check_map(all->map.use);
	handle_rgb(all);
	check_textures(all);
	all->data.map = all->map.use;
}

void	ft_parsing(t_all *all, char *av)
{
	all->map.name = av;
	read_map(all);
	put_them_in_the_place(all);
	is_they_valid(all);
}
