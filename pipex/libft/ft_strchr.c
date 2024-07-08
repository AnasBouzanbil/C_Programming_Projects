/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:57:56 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/21 19:09:36 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	x;
	size_t	l;
	size_t	i;

	x = (char)c;
	i = 0;
	l = ft_strlen(str);
	while (l >= i)
	{
		if (str[i] == x)
		{
			return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
