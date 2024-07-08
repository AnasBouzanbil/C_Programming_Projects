/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:21:37 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/08 21:28:56 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	where_is_line(char *storage)
{
	int	i;

	i = 0;
	while (storage && storage[i])
	{
		if (storage[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*gnl_strsub(const char *str, int begin, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ptr = malloc(sizeof(char) * (end - begin + 1));
	if (ptr == NULL)
		return (NULL);
	while (begin < end && str[begin])
	{
		ptr[i] = str[begin];
		begin++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_after_line(char *storage)
{
	int		i;
	int		x;
	char	*str;

	if (storage == NULL || storage[0] == '\0')
		return (0);
	i = 0;
	x = where_is_line(storage);
	if (x == 0)
		return (0);
	str = malloc((gnl_strlen(storage) - x) + 1);
	if (str == NULL)
		return (NULL);
	while (storage[x])
		str[i++] = storage[x++];
	str[i] = '\0';
	return (str);
}

char	*get_until_line(char *storage)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!storage[0])
		return (NULL);
	while (storage[x] && storage[x] != '\n')
		x++;
	if (storage[x] == '\n')
		x++;
	return (gnl_strsub(storage, 0, x));
}
