/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:11:12 by abouzanb          #+#    #+#             */
/*   Updated: 2021/09/29 08:12:03 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int a) // the return type is void because the function does not return anything (it just displays a character on the screen).
{
	if (a >= 0) // if the number is greater than or equal to 0, then it is positive.
	{
		write(1, "P", 1); // write the character 'P' to the standard output.
	}
	else
	{
		write(1, "N", 1);
	}
}
