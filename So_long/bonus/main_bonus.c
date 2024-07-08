/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:58:18 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/12 15:49:51 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	rest(t_path *str)
{
	int	i;

	i = 0;
	while (str->oneline[i])
	{
		if (str->oneline[i] == '\n')
		{
			if (str->oneline[i + 1] == '\n')
			{
				write(2, "Error\n map is invalide\n", 23);
				exit(1);
			}
		}
		i++;
	}
	return (i);
}

void	check_other_char(t_path *str)
{
	int	i;

	i = 0;
	while (str->oneline[i])
	{
		if (str->oneline[i] != 'P' && str->oneline[i] != 'C'
			&& str->oneline[i] != '1' && str->oneline[i] != 'E'
			&& str->oneline[i] != '0' && str->oneline[i] != '\n')
		{
			write(1, "Error\n The map contain other characters\n", 40);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_path	str;
	t_map	ptr;

	if (argc == 1 || argc >= 3)
	{
		write(2, "Error\n Oh! there is a problem with the map name !\n", 40);
		return (1);
	}
	str.t_pathname = argv[1];
	str.oneline = NULL;
	read_t_map(&str);
	ptr.mlx = mlx_init();
	ptr.mlx_win = mlx_new_window(ptr.mlx, (str.length * 50) \
		+ 50, (str.raws * 50), "My_So_Long");
	set_images(&ptr, &str);
	ptr.str = &str;
	mlx_key_hook(ptr.mlx_win, check_key, &ptr);
	mlx_hook(ptr.mlx_win, 17, 0, ft_close, &ptr);
	mlx_loop(ptr.mlx);
	close(str.fd);
	return (0);
}
