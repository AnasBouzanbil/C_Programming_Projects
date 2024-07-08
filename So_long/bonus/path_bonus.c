/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:54:56 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/12 15:51:08 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_t_map(t_path *str)
{
	int	i;

	if (str->oneline == NULL || str->oneline[0] == '\0'
		|| str->oneline[0] == '\n')
	{
		write(2, "Error\n map is invalide  \n", 25);
		exit(1);
	}
	i = rest(str);
	if (str->oneline[i - 1] == '\n')
	{
		write(2, "Error\n map is ending with newline\n", 34);
		exit(1);
	}
}

void	fun(int x, t_path *str)
{
	int	i;

	i = 0;
	while (str->map[0][i])
	{
		if (str->map[0][i] != '1' || str->map[x][i] != '1')
		{
			write(2, "Error\n Please check the walls\n", 30);
			exit(1);
		}
		i++;
	}
}

void	check_walls(t_path *str)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	str->length = ft_strlen(str->map[0]) - 1;
	while (str->map[x])
	{
		if (str->map[x][0] != '1' || str->map[x][str->length] != '1')
		{
			write(2, "Error\n Please check the walls\n", 30);
			exit(1);
		}
		x++;
	}
	str->raws = x;
	x--;
	fun(x, str);
}

void	read_help_fun(t_path *str)
{
	if (str->oneline == NULL)
	{
		write(2, "Error\n map is empty\n", 21);
		exit(1);
	}
	check_t_map(str);
	is_valid(str);
	check_other_char(str);
	isit_valid(str);
	check_walls(str);
	scaning_t_map(str);
}

void	read_t_map(t_path *str)
{
	char	*ptr;

	check_t_path_name(str);
	str->fd = open(str->t_pathname, O_RDWR);
	if (str->fd == -1)
	{
		write(2, "Error\n Could not find the file\n", 31);
		exit(1);
	}
	ptr = get_next_line(str->fd);
	while (ptr)
	{
		str->oneline = gnl_strjoin(str->oneline, ptr);
		free(ptr);
		ptr = get_next_line(str->fd);
	}
	read_help_fun(str);
}
