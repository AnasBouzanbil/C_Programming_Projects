/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:31:21 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 02:33:19 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_ele(char **str)
{
	t_l	l;

	l.a = 0;
	l.i = 0;
	ft_help_check_ele(str, &l);
	if (l.player != 1 || l.wall == 0 || l.space == 0)
		exit(write(2, "Error\nMmmmm! there is a problem in characters\n", 46));
}

void	ft_help_my_flood_fill(char **map, int i, int x)
{
	if (map[i + 1][x] == '\n' || map[i + 1][x] == '\0' || map[i + 1][x] == ' ')
		exit(write(2, "Error\nThe Map is not rounded with walls\n", 40));
	else if (map[i - 1][x] == '\0' || map[i - 1][x] == ' ')
		exit(write(2, "Error\nThe Map is not rounded with walls444\n", 44));
	else if (map[i][x - 1] == '\n' || map[i][x - 1] == '\0' \
	|| map[i][x - 1] == ' ')
		exit(write(2, "Error\nThe Map is not rounded with walls\n", 40));
	else if (map[i][x + 1] == '\n' || map[i][x + 1] == '\0' \
	|| map[i][x + 1] == ' ')
		exit(write(2, "Error\nThe Map is not rounded with walls\n", 40));
}

void	my_flood_fill(char **map)
{
	int	i;
	int	x;

	i = 1;
	while (map[i + 1])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == '0' || map[i][x] == 'W' \
			|| map[i][x] == 'E' || map[i][x] == 'S' || map[i][x] == 'N')
				ft_help_my_flood_fill(map, i, x);
			x++;
		}
		i++;
	}
	x = 0;
	while (map[i][x])
	{
		if (map[i][x] != '1' && map[i][x] != ' ' && map[i][x] != '\n')
			exit(write(2, "Error\nthe map is not closed with the walls\n", 44));
		x++;
	}
}

void	check_new_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n')
			exit(write(2, "Error\nOne or more consecutives newline\n", 40));
		i++;
	}
}

void	check_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	check_ele(map);
	check_new_line(map);
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\n' && map[0][i] != ' ')
			exit(write(2, "error\nWait! wait! the wall is not closed\n\
			Please make sure everything is correct\n", 84));
		i++;
	}
	my_flood_fill(map);
}
