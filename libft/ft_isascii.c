/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:54:22 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/07 18:54:24 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a) // This function checks if the character is a 7-bit unsigned char, going from 0 to 127. 
{
	if (a <= 127 && a >= 0)
		return (1);
	return (0);
}
