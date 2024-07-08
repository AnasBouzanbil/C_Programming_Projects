/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:31 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/29 02:42:36 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{ // This function locates the first occurrence of the null-terminated string to_find in the string str, where not more than len characters are searched.
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && len == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j < len))
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *) str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
