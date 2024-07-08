/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:07:35 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 02:30:49 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*return_elements(char *str)
{
	char	*ptr;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	ptr = calloc((ft_strlen(str) - i) + 1, 1);
	while (str[i] && str[i] != '\n')
		ptr[x++] = str[i++];
	ptr[x] = '\0';
	return (ptr);
}

void	put_it(t_all *all, char *name)
{
	if (strncmp(name, "EA", 2) == 0)
		all->elem->ea = return_elements(name + 2);
	if (strncmp(name, "SO", 2) == 0)
		all->elem->so = return_elements(name + 2);
	if (strncmp(name, "NO", 2) == 0)
		all->elem->no = return_elements(name + 2);
	if (strncmp(name, "WE", 2) == 0)
		all->elem->we = return_elements(name + 2);
	if (strncmp(name, "F", 1) == 0)
		all->elem->f_temp = return_elements(name + 1);
	if (strncmp(name, "C", 1) == 0)
		all->elem->c_temp = return_elements(name + 1);
}

void	ft_put_map(char *key, char *name, int *x)
{
	int	i;

	i = 0;
	ft_strlcpy(key, name, ft_strlen(name));
	free(name);
	*x = *x + 1;
}

void	init(char **use, t_all *all)
{
	int	i;

	i = 0;
	while (i < all->map.row_number)
	{
		use[i] = calloc(sizeof(char) *(all->map.big_size + 1), 1);
		i++;
	}
}

int	all_is_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
