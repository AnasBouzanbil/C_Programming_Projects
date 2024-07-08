/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:18:00 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/07 20:26:26 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(const char *str1, const char *str2)
{
	size_t	x;
	size_t	str1lenth;
	size_t	str2lenth;

	x = 0;
	str1lenth = 0;
	str2lenth = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[str1lenth])
		str1lenth++;
	while (str2[str2lenth])
		str2lenth++;
	while (x <= str1lenth && x <= str2lenth)
	{
		if (str1[x] != str2[x])
		{
			return ((unsigned char)str1[x] - (unsigned char)str2[x]);
		}
		x++;
	}
	return (0);
}
