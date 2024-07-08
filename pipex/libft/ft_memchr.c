/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:57:28 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/22 16:45:33 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	size_t			x;
	unsigned char	*str;
	unsigned char	realvalue;

	realvalue = (unsigned char) value;
	x = 0;
	str = (unsigned char *)ptr;
	while (x < num)
	{
		if (str[x] == realvalue)
			return (str + x);
		x++;
	}
	return (NULL);
}
