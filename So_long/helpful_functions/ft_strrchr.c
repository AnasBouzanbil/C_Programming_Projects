/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:37 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/07 21:57:26 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int c)
{
	int	x;

	if (!str)
		return (0);
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
