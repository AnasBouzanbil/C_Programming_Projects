/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:38:59 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/12 15:48:26 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isit_valid(t_path *str)
{
	check_char(str);
	if (str->c <= 0 || str->e != 1 || str->p != 1)
	{
		write(2, "Error\n L map machi valide\n", 26);
		exit(1);
	}
}

void	check_t_path_name(t_path *str)
{
	if (ft_strncmp(ft_strrchr(str->t_pathname, '.'), ".ber") != 0)
	{
		write(2, "Error\n the path name is invalide \n", 34);
		exit(1);
	}
}

void	get_id(t_map *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str->str->map[x])
	{
		i = 0;
		while (str->str->map[x][i])
		{
			if (str->str->map[x][i] == 'P')
			{
				str->raw_id = x;
				str->lenth_id = i;
				return ;
			}
			i++;
		}
		x++;
	}
}

void	is_valid(t_path *str)
{
	int	i;
	int	x;
	int	k;

	i = 0;
	str->map = ft_split(str->oneline, '\n');
	if (str->map == NULL)
		exit(1);
	k = ft_strlen(str->map[0]);
	while (str->map[i])
	{
		x = ft_strlen(str->map[i]);
		if (x != k)
		{
			write(2, "Error\n L map machi valide\n", 27);
			exit(1);
		}
		i++;
	}
}

int	ft_close(int i)
{
	exit(0);
	return (i);
}
