/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:29:03 by abouzanb          #+#    #+#             */
/*   Updated: 2021/09/29 08:30:14 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	a; // Declare a variable 'a' of type char to store the character we want to display.
// its the same as the previous exercises but this time we have to display numbers from 0 to 9.
	a = '0'; // Start with the character '0' as the initial value of 'a'. note that '0' is not the same as 0. '0' is a character and 0 is a number.
	while (a <= '9') // Repeat the following block of code until 'a' reaches '9'.
	{
		write(1, &a, 1);
		a++;
	}
}
