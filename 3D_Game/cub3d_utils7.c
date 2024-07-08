/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:30:57 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 15:35:01 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	set_it(t_all *all, char *c, char *f)
{
	char	**ff;
	char	**cc;

	ff = ft_split(f, ',');
	cc = ft_split(c, ',');
	count_str(ff);
	count_str(cc);
	initilaized(all, ff, cc);
	free_str(ff);
	free_str(cc);
}

void	handle_rgb(t_all *all)
{
	set_it(all, all->elem->c_temp, all->elem->f_temp);
}

void	ft_counting_map_size(t_all *all)
{
	int		fd;
	char	*temp;

	fd = open(all->map.name, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Error\nSEGV: could not open the file\nMaybe the file \
is not existe or the permission does not allowed to open the file\n", 118));
	temp = get_next_line(fd);
	all->map.row_number = 0;
	all->map.big_size = 0;
	while (temp)
	{
		all->map.row_number++;
		if (all->map.big_size < ft_strlen(temp))
			all->map.big_size = ft_strlen(temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

void	check_validaiton_name(char *name)
{
	char	*temp;

	if (name == NULL || name[0] == '\0')
		exit(write(2, "Error\nSEGV: File name is empty or not valid\n", 45));
	temp = strrchr(name, '.');
	if (temp == NULL)
		exit(write(2, "Error\nThe file does not containe any extansion\n", 48));
	if (strcmp(temp, ".cub"))
		exit(write(2, "Error\nSEGV\nThe File doe not contain the extansion \
'.cub'\nplease add the '.cub'extanson to the your map file\n", 109));
}

void	read_map(t_all *all)
{
	char	*temp;
	int		fd;
	int		i;

	i = 0;
	check_validaiton_name(all->map.name);
	ft_counting_map_size(all);
	fd = open(all->map.name, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Error\nCould not open the file\nMaybe the file \
is not existe or the permission does not allowed to open the file\n", 112));
	temp = get_next_line(fd);
	if (temp == NULL)
		exit(write(2, "Error\nThe File \".cub\" is not containing anything\n", 50));
	all->map.map = calloc(sizeof(char *) * (all->map.row_number + 1), 1);
	while (temp)
	{
		all->map.map[i] = strdup(temp);
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	all->map.map[i] = NULL;
	close(fd);
}
