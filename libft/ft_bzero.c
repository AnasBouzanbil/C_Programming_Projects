/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:35 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/07 18:53:37 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n) // This function writes n zeroed bytes to the string s.
{
	char	*str; // Declare a char pointer to the string s.
	size_t	x; // Declare a size_t variable to use as a counter.

	str = (char *)s; // Cast the string s to a char pointer and assign it to the char pointer str. This is done to be able to iterate through the string s character by character
	x = 0;
	while (x < n) // Iterate through the string s character by character until the end of the string is reached.
	{
		str[x] = 0; // Set the current character to 0.
		x++; // move to the next character.
	}
}
