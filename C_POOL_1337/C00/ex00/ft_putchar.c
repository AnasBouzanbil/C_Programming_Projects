/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:36:03 by abouzanb          #+#    #+#             */
/*   Updated: 2021/09/28 11:20:24 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // The unistd.h header defines the following symbolic constants for the file access permission bits. we  declare it to use the write() function.

// You have look up about what variables are and how they work in C

void	ft_putchar(char c) // the return type is void because the function does not return anything (it just displays a character on the screen).
{ // write() is a system call that writes count bytes from the buffer pointed to by buf to the file referred to by the file descriptor fd.
	write(1, &c, 1); // the first  argument is the file descriptor, the second is the buffer, and the third is the number of bytes to write.
} 
/*
bdarija :
had la fonction ghadi t afficher un seul caractere f l ecran

kifach atkhdem had fonction ?

ghadi t cree wahed function atsmiha main
had main hia awl function li ghadi t executiha l compiler
kifch ? 
compiler mli aybda y9ra l code dialk aybda y9rah men main function 

kifach adiclariha ?
int main(void) // hadi hiya declaration dial main function
{
	// l compiler aybda ye9ra l code dialk men hena
	// hena daba aykhsek t3yt 3la function ta3 ft_putchar
	// kifach ?
	// ghadi dir smiya ta3 l function and dir parentheses fih wahed char " bi3men3na 3tiha chi charactere t afficih f l ecran "
	ft_putchar('a');
	// daba ghadi t afficher l character 'a' f l ecran meli t compile l code dialk o t executih 
	return (0);
}

*/


/*
The ft_putchar function is a simple piece of code that allows you to display a single character on the screen.
It uses the write() command to send the character to the standard output, which typically represents the screen.
Essentially, when you call this function and pass a character as an argument, 
that character will be shown on the screen for you to see.
*/