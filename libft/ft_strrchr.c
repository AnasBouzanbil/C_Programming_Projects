/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:37 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/21 18:37:46 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	x;

	x = ft_strlen(str);
	while (x >= 0)
	{
		if (str[x] == (char)c)
		{
			return ((char *)str + x);
		}
		x--;
	}
	return (NULL);
}
// This function returns a pointer to the last occurrence of the character c in the string str.