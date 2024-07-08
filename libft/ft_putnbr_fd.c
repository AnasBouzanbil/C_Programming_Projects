/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:59:56 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/29 02:23:56 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int k, int fd) // This function outputs the integer ’n’ to the given file descriptor.
{
	if (k == -2147483647 -1)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (k < 0)
	{
		k = k * -1;
		ft_putchar_fd('-', fd);
	}
	if (k >= 10)
	{
		ft_putnbr_fd(k / 10, fd);
		k = k % 10;
	}
	if (k < 10)
	{
		ft_putchar_fd(k + '0', fd);
	}
}
