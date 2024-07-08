/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:58:10 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/25 01:59:08 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{  // This function copies n bytes from memory area src to memory area dest.
	char	*str;
	char	*ptr;

	str = (char *)src;
	ptr = (char *)dst;
	if (str < ptr)
	{
		while (len > 0)
		{
			len--;
			ptr[len] = str[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
