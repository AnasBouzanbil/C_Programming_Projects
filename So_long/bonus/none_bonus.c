/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:53 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/12 15:50:04 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_path *str, int raw, int p)
{
	if (raw < 0 || p < 0 || p >= str->length || raw >= str->raws || \
		str->fake_map[raw][p] == 'E' || str->fake_map[raw][p] == '1')
		return ;
	if (str->fake_map[raw][p] == 'C')
		str->fake_c++;
	str->fake_map[raw][p] = '1';
	flood_fill(str, raw, p - 1);
	flood_fill(str, raw, p + 1);
	flood_fill(str, raw + 1, p);
	flood_fill(str, raw - 1, p);
}

void	check_char(t_path *str)
{
	int	i;

	i = 0;
	str->p = 0;
	str->c = 0;
	str->e = 0;
	while (str->oneline[i])
	{
		if (str->oneline[i] == 'P')
			str->p++;
		else if (str->oneline[i] == 'C')
			str->c++;
		else if (str->oneline[i] == 'E')
			str->e++;
		i++;
	}
}

void	flood_door(t_path *str, int raw, int p)
{
	if (raw < 0 || p < 0 || p >= str->length || raw >= str->raws
		|| str->fake_map[raw][p] == '1')
		return ;
	if (str->fake_map[raw][p] == 'E')
		str->fake_door++;
	str->fake_map[raw][p] = '1';
	flood_door(str, raw, p - 1);
	flood_door(str, raw, p + 1);
	flood_door(str, raw + 1, p);
	flood_door(str, raw - 1, p);
}

void	freeing(t_path *str)
{
	int	x;

	x = 0;
	while (str->fake_map[x])
		free(str->fake_map[x++]);
	free(str->fake_map);
}

void	scaning_t_map(t_path *str)
{
	int	raw;
	int	p;

	str->fake_map = ft_split(str->oneline, '\n');
	str->fake_c = 0;
	str->fake_door = 0;
	location(&raw, &p, str);
	flood_fill(str, raw, p);
	freeing(str);
	str->fake_map = ft_split(str->oneline, '\n');
	flood_door(str, raw, p);
	if (str->c != str->fake_c || str->fake_door != 1)
	{
		write(2, "Error\n map invalid !\n", 21);
		exit (1);
	}
}
