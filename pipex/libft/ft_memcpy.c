/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:57:41 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/22 22:45:28 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t i)
{
	char	*s;
	char	*di;
	size_t	b;

	s = (char *)src;
	di = (char *)dest;
	if (!s && !di)
		return (NULL);
	b = 0;
	while (b < i)
	{
		di[b] = s[b];
		b++;
	}
	return (dest);
}
