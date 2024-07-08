/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:00:51 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/25 01:51:33 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	x;
	size_t	size_compare;

	x = 0;
	size_compare = 0;
	if (size == 0)
		return (ft_strlen(str));
	while (str[x] != '\0' && size_compare < (size - 1))
	{
		dest[x] = str[x];
		x++;
		size_compare++;
	}
	dest[x] = '\0';
	return (ft_strlen(str));
}
