/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:09 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 04:18:53 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	x;

	x = 0;
	if (!s || !f)
		return ;
	while (s[x])
	{
		f(x, &s[x]); // Apply the function f to the current character of the string s.
		x++;
	}
}

/*
what is  the difference between  ft_striteri  and ft_strmapi ?

ft_striteri  is a function that applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.

ft _strmapi  is a function that applies the function f to each character of the string passed as argument to create a new string (with malloc(3)) resulting from successive applications of f.

*/