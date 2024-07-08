/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:56:38 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/08 22:45:59 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "so_long_bonus.h"

int	move_left(t_map *ptr)
{
	get_id(ptr);
	if (ptr->str->map[ptr->raw_id][ptr->lenth_id - 1] == 'C' ||
		ptr->str->map[ptr->raw_id][ptr->lenth_id - 1] == '0')
	{
		if (ptr->str->map[ptr->raw_id][ptr->lenth_id - 1] == 'C')
			ptr->str->c--;
		ptr->str->map[ptr->raw_id][ptr->lenth_id - 1] = 'P';
		ptr->str->map[ptr->raw_id][ptr->lenth_id] = '0';
	}
	else if (ptr->str->map[ptr->raw_id][ptr->lenth_id - 1] == 'E')
	{
		if (ptr->str->c == 0)
		{
			write(1, BHMAG"\n\n\n		Booh You won man	\n\n\n"RESET, 30);
			exit(0);
		}
		return (1);
	}
	else
		return (1);
	set_images(ptr, ptr->str);
	return (0);
}

int	move_right(t_map *ptr)
{
	get_id(ptr);
	if (ptr->str->map[ptr->raw_id][ptr->lenth_id + 1] == 'C' ||
		ptr->str->map[ptr->raw_id][ptr->lenth_id + 1] == '0')
	{
		if (ptr->str->map[ptr->raw_id][ptr->lenth_id + 1] == 'C')
			ptr->str->c--;
		ptr->str->map[ptr->raw_id][ptr->lenth_id + 1] = 'P';
		ptr->str->map[ptr->raw_id][ptr->lenth_id] = '0';
	}
	else if (ptr->str->map[ptr->raw_id][ptr->lenth_id + 1] == 'E')
	{
		if (ptr->str->c == 0)
		{
			write(1, BHMAG"\n\n\n		Booh You won man	\n\n\n"RESET, 30);
			exit(0);
		}
		return (1);
	}
	else
		return (1);
	set_images(ptr, ptr->str);
	return (0);
}

int	move_down(t_map *ptr)
{
	get_id(ptr);
	if (ptr->str->map[ptr->raw_id + 1][ptr->lenth_id] == 'C' ||
		ptr->str->map[ptr->raw_id + 1][ptr->lenth_id] == '0')
	{
		if (ptr->str->map[ptr->raw_id + 1][ptr->lenth_id] == 'C')
			ptr->str->c--;
		ptr->str->map[ptr->raw_id + 1][ptr->lenth_id] = 'P';
		ptr->str->map[ptr->raw_id][ptr->lenth_id] = '0';
	}
	else if (ptr->str->map[ptr->raw_id + 1][ptr->lenth_id] == 'E')
	{
		if (ptr->str->c == 0)
		{
			write(1, BHMAG"\n\n\n		Booh You won man	\n\n\n"RESET, 30);
			exit(0);
		}
		return (1);
	}
	else
		return (1);
	set_images(ptr, ptr->str);
	return (0);
}

int	move_up(t_map *ptr)
{
	get_id(ptr);
	if (ptr->str->map[ptr->raw_id - 1][ptr->lenth_id] == 'C' ||
		ptr->str->map[ptr->raw_id - 1][ptr->lenth_id] == '0')
	{
		if (ptr->str->map[ptr->raw_id -1][ptr->lenth_id] == 'C')
			ptr->str->c--;
		ptr->str->map[ptr->raw_id - 1][ptr->lenth_id] = 'P';
		ptr->str->map[ptr->raw_id][ptr->lenth_id] = '0';
	}
	else if (ptr->str->map[ptr->raw_id - 1][ptr->lenth_id] == 'E')
	{
		if (ptr->str->c == 0)
		{
			write(1, BHMAG"\n\n\n		Booh You won man	\n\n\n"RESET, 30);
			exit(0);
		}
		return (1);
	}
	else
		return (1);
	set_images(ptr, ptr->str);
	return (0);
}

int	check_key(int key, t_map *str)
{
	static int	i;
	int			status;
	char		*ltr;

	status = 1;
	if (key == 53)
		exit(0);
	if (key == 0 || key == 123)
		status = move_left(str);
	else if (key == 2 || key == 124)
		status = move_right(str);
	else if (key == 1 || key == 125)
		status = move_down(str);
	else if (key == 13 || key == 126)
		status = move_up(str);
	if (status == 0)
	{
		i++;
		ltr = ft_itoa(i);
		mlx_string_put(str->mlx, str->mlx_win,
			0, 0, 0x00FF0000, "Move Number : ");
		mlx_string_put(str->mlx, str->mlx_win, 10, 15, 0x00FF0000, ltr);
		free(ltr);
	}
	return (0);
}
