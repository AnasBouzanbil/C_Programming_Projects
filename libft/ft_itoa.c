/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:56:12 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/27 00:32:56 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_lenth(int a)
{
	int	x;

	x = 0;
	if (a == 0)
	{
		return (1);
	}
	if (a < 0)
	{
		a = a * -1;
		x++;
	}
	while (a > 0)
	{
		a = a / 10;
		x++;
	}
	return (x);
}

static void	helper_function(char *str, int a, int x) // This helper function is used to fill the string with the digits of the integer.
{
	if (a < 0) // If the integer is negative, set the first character of the string to '-' and multiply the integer by -1 to make it positive.
	{
		str[0] = '-'; // Set the first character of the string to '-'.
		a = a * -1;
	}
	if (a == 0) // If the integer is 0, set the first character of the string to '0'.
	{
		str[0] = '0';
	}
	while (a > 0) // Iterate through the integer digit by digit and set the corresponding character of the string to the digit.
	{
		str[x] = (a % 10) + '0'; /// Set the current character of the string to the digit.
		x--; // Decrement the counter x by one to move to the next character of the string. 
		a = a / 10; // Divide the integer by 10 to move to the next digit.
	}
}

char	*ft_itoa(int a) // ` ft_itoa ` converts an integer to a string.
{
	int		x;
	char	*str; // Declare a char pointer to the string that will be returned.

	if (a == -2147483648) // Check for the special case of the minimum value for an int variable.
		return (ft_strdup("-2147483648")); // If the input is the minimum value for an int variable, return a copy of the string "-2147483648".
	x = ft_number_lenth(a); // Get the length of the string that will be returned.
	str = (char *)malloc(sizeof(char) * (x + 1)); // Allocate memory for the string that will be returned.
	if (str == NULL)
		return (NULL);
	str[x] = '\0'; // Set the last character of the string to '\0'.
	x--; // Decrement the counter x by one to start from the last character of the string.
	helper_function(str, a, x); // Call the helper function to fill the string with the digits of the integer.
	return (str);
}
