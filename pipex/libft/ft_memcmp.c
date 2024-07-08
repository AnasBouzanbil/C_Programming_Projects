/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:57:43 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/19 23:00:53 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr;
	unsigned char	*str;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)ptr1;
	str = (unsigned char *)ptr2;
	while (i < num)
	{
		if (str[i] != ptr[i])
		{
			return (ptr[i] - str[i]);
		}
		i++;
	}
	return (0);
}
