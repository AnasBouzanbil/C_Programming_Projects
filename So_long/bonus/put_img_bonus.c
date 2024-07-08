/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:55:05 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/10 19:24:41 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	location(int *raw, int *p, t_path *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str->fake_map[x])
	{
		i = 0;
		while (str->fake_map[x][i])
		{
			if (str->fake_map[x][i] == 'P')
			{
				*raw = x;
				*p = i;
				return ;
			}
			i++;
		}
		x++;
	}
}

void	put_images(t_map *ptr)
{
	int	i;
	int	x;

	ptr->door = mlx_xpm_file_to_image(ptr->mlx, "./img/door.xpm", &x, &i);
	ptr->coll = mlx_xpm_file_to_image(ptr->mlx, "./img/coin.xpm", &x, &i);
	ptr->walls = mlx_xpm_file_to_image(ptr->mlx, "./img/wall.xpm", &i, &x);
	ptr->space = mlx_xpm_file_to_image(ptr->mlx, "./img/bg.xpm", &i, &x);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./img/l3ab.xpm", &i, &x);
	if (ptr->coll == NULL || ptr->door == NULL || ptr->space == NULL || \
		ptr->walls == NULL || ptr->player == NULL)
	{
		write (2, "invalid xpm file  !\n", 20);
		exit(1);
	}
}

void	help(t_map *ptr, t_path *str, int x, int i)
{
	if (str->map[x][i] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->walls, i * 50, x * 50);
	else if (str->map[x][i] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->door, (i * 50), (x * 50));
	else if (str->map[x][i] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->coll, (i * 50), (x * 50));
	else if (str->map[x][i] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->space, (i * 50), (x * 50));
	else if (str->map[x][i] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player, (i * 50), (x * 50));
}

void	set_images(t_map *ptr, t_path *str)
{
	int	i;
	int	x;

	put_images(ptr);
	x = 0;
	while (str->map[x])
	{
		i = 0;
		while (str->map[x][i])
		{
			help(ptr, str, x, i);
			i++;
		}
		x++;
	}
}
