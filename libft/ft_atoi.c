/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:23 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 19:49:48 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "libft.h"
static int helper_function(const char *s, int *type)
{
    // This function is used to skip the spaces and signs in the string.
     
    int i = 0;
    
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
        || s[i] == '\v' || s[i] == '\f' || s[i] == '\r') // Skip space  and other white spaces in the string
        i++;

    if (s[i] == '+' || s[i] == '-') // Check if the number is positive or negative
    {
        if (s[i] == '-') // Check if the number is negative
            *type = -1; // Set the type to negative in order to multiply the number by -1 later on in the function ft_atoi
        i++; // Skip the sign in the string
    }
    
    return i;
}

int ft_atoi(const char *s)
{
    // This function converts a string to an integer. It is a recreation of the atoi function.
    
    int i;
    long x;
    int type;
    int l;

    type = 1;
    i = helper_function(s, &type); // Skip spaces and signs
    x = 0;
    l = 0;

    while (s[i] <= '9' && s[i] >= '0')
    {
        x = x * 10 + (s[i] - 48); // Convert the string to an integer

        if (l > x)
        {
            if (type < 0)
                return 0; // Check for negative number overflow
            else if (type > 0)
                return -1; // Check for positive number overflow
        }

        i++;
        l = x;
    }

    return x * type; // Return the converted integer
}

/*
Description:
The ft_atoi() function converts the initial portion of the string pointed to by s to an int representation.
It skips any leading spaces and signs, and then converts the remaining numeric characters to an integer.
If the number is too large to be represented as an int, it returns 0 for negative numbers and -1 for positive numbers.
This function is a recreation of the atoi() function.
*/
