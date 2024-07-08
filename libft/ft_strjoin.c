/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:11:52 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 04:19:22 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2) // This function allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
{
	int		lenth;
	int		lenth2;
	char	*ptr;

	if (!str1 || !str2)
		return (NULL);
	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(str1)+ ft_strlen(str2) + 1));
	if (ptr == NULL)
		return (NULL);
	lenth = 0;
	lenth2 = 0;
	while (str1[lenth] != '\0')
	{
		ptr[lenth] = str1[lenth];
		lenth++;
	}
	while (str2[lenth2] != '\0')
	{
		ptr[lenth] = str2[lenth2];
		lenth++;
		lenth2++;
	}
	ptr[lenth] = '\0';
	return (ptr);
}
