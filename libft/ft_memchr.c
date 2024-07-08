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

	realvalue = (unsigned char) value; // Cast the value to an unsigned char and assign it to the unsigned char realvalue.
	x = 0;
	str = (unsigned char *)ptr; // Cast the pointer to an unsigned char pointer and assign it to the unsigned char pointer str. This is done to be able to iterate through the string b character by character.
	while (x < num)
	{
		if (str[x] == realvalue) // If the current character is equal to the value c, return the address of the current character.
			return (str + x); // Cast the address of the current character to an unsigned char pointer and return it.
		x++;
	}
	return (NULL);
}
// Description
// The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.