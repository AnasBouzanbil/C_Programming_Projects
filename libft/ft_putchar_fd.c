/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:59:01 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/07 18:59:03 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
} // This function outputs the character c to the given file descriptor.

/*
Wait a minute, what is a file descriptor?
A file descriptor is a non-negative integer that uniquely identifies an open file in a computer's operating system. It describes a data resource, and how that resource may be accessed.

so file descriptor nothing just a number that identifies a file. when you open a file, the operating system creates an entry to represent that file and store the information about that opened file. So if you open a file, it will be assigned a file descriptor. If your system supports 10000 open files, then file descriptor can be values from 0 to 9999.						

0 is the standard input (stdin) that is the keyboard
1 is the standard output (stdout) that is the screen
2 is the standard error (stderr) that is the screen

and you can open a file and assign it a file descriptor, and then you can write to it or read from it using that file descriptor.

*/