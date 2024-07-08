/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:58:25 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 04:21:18 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n) // This function writes n bytes of value c (converted to an unsigned char) to the string b.
{
	char	*ptr; // Declare a char pointer to the string b.
	size_t	a; // Declare a size_t variable to use as a counter.

	ptr = (char *) str; // Cast the string b to a char pointer and assign it to the char pointer ptr. This is done to be able to iterate through the string b character by character.
	a = 0;
	while (a < n) // Iterate through the string b character by character until the end of the string is reached.
	{
		ptr[a] = c; // Set the current character to the value c.
		a++; // move to the next character.
	}
	return (str);
} // The function returns the string b.
