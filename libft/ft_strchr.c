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

	x = (char)c; // Cast the integer c to a char and assign it to the char x. This is done to be able to compare the characters of the string to the character c.
	i = 0;
	l = ft_strlen(str);
	while (l >= i) // Iterate through the string character by character until the end of the string is reached.
	{
		if (str[i] == x) // If the current character is equal to the character c, return the address of the current character.
		{
			return ((char *)str + i); // Cast the address of the current character to a char pointer and return it.
		}
		i++;
	}
	return (0);
}
