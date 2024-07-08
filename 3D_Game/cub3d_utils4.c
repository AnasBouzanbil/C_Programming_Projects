/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceddibao <ceddibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:41:23 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/15 11:49:50 by ceddibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;
	size_t	lenth;
	size_t	strlenth;

	a = 0;
	if (!str)
		return (NULL);
	strlenth = ft_strlen(str);
	lenth = len;
	if (strlenth < len)
		lenth = strlenth - start;
	if (strlenth < start)
		lenth = 0;
	ptr = (char *)malloc(sizeof(char) * (lenth + 1));
	if (ptr == NULL)
		return (NULL);
	while (a < lenth && str[start])
	{
		ptr[a] = str[start];
		a++;
		start++;
	}
	ptr[a] = '\0';
	return (ptr);
}

static int	check_is_set(const char *set, char cut)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == cut)
			return (1);
		i++;
	}
	return (0);
}

static void	help_function(const char *s1, int i, int lenth, char *str)
{
	int	x;

	x = 0;
	while (s1[i] != '\0' && i < lenth)
	{
		str[x] = s1[i];
		i++;
		x++;
	}
	str[x] = '\0';
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		x;
	int		lenth;
	int		lenth2;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	lenth = ft_strlen(s1);
	x = 0;
	i = 0;
	lenth2 = lenth;
	while (check_is_set(set, s1[i]))
		i++;
	if (i == lenth)
		return (NULL);
	while (check_is_set(set, s1[lenth - 1]))
		lenth--;
	str = (char *)malloc(sizeof(char) * ((lenth - i) + 1));
	if (str == NULL)
		return (NULL);
	help_function(s1, i, lenth, str);
	return (str);
}

void	do_put_for_x(t_data *data, unsigned int *toput)
{
	if (e_w(data) == 'E')
	{
		data->fill_x = data->inter_y * (float)data->ea.text_width / 16;
		if (data->fill_x > data->ea.text_width)
			data->fill_x %= data->ea.text_width;
		data->fill_y = (int)((data->wall_start) * \
		data->ea.text_height / data->wall_height);
		data->fill_offset = data->fill_y * data->ea.text_line_lenght + \
		data->fill_x * (data->ea.bit_per_pixel / 8);
		*toput = *(unsigned int *)(data->ea.text + data->fill_offset);
	}
	else
	{
		data->fill_x = data->inter_y * (float)data->we.text_width / 16;
		if (data->fill_x > data->we.text_width)
			data->fill_x %= data->we.text_width;
		data->fill_y = (int)((data->wall_start) * \
		data->we.text_height / data->wall_height);
		data->fill_offset = data->fill_y * data->we.text_line_lenght \
		+ data->fill_x * (data->we.bit_per_pixel / 8);
		*toput = *(unsigned int *)(data->we.text + data->fill_offset);
	}
}
