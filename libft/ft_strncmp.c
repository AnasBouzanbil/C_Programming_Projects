/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:18:00 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/29 02:01:40 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{ // This function compares the first n bytes of the string str1 to the string str2.
	size_t	x;
	size_t	str1lenth;
	size_t	str2lenth;

	x = 0;
	str1lenth = 0;
	str2lenth = 0;
	while (str1[str1lenth]) // Get the length of the string str1.
		str1lenth++;
	while (str2[str2lenth]) // the same for str2.
		str2lenth++;
	while (x < n && x <= str1lenth && x <= str2lenth)
	{
		if (str1[x] != str2[x]) // If the current character of str1 is not equal to the current character of str2, return the difference between the current character of str1 and the current character of str2.
		{
			return ((unsigned char)str1[x] - (unsigned char)str2[x]); // Cast the current character of str1 and str2 to an unsigned char and return the difference between them.
		}
		x++;
	}
	return (0);
}
