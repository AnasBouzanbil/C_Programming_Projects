/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:41:25 by abouzanb          #+#    #+#             */
/*   Updated: 2021/09/28 14:36:20 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_alphabet(void) // the return type is void because the function does not return anything (it just displays a character on the screen). 
// and it takes no arguments.
{
	char	c; // Declare a variable 'c' of type char to store the character we want to display.

	c = 'a'; // Start with the character 'a' as the initial value of 'c'.

	while (c <= 'z') // Repeat the following block of code until 'c' reaches 'z'.
	{
		write(1, &c, 1); // Display the character stored in 'c' using the write() function.
		c++; // Increment the value of 'c' by 1 to move to the next character in the alphabet.
	}
}

/* 
   You can also use the ft_putchar function (not shown here) to display the alphabet from 'a' to 'z'.
   If you're new to programming, it's helpful to learn about ASCII codes to understand how characters are represented and manipulated in code.
*/