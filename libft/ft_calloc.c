/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:02:28 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/28 22:42:01 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size) // ` ft_calloc ` allocates memory for an array of ` count ` elements of ` size ` bytes each and returns a pointer to the allocated memory. The memory is set to zero.
{
	void	*ptr; // Declare a void pointer to the allocated memory.

	if (count && SIZE_MAX / count < size) // Check for overflow. If the multiplication of ` count ` and ` size ` is greater than the maximum value for a size_t variable, return NULL.
		return (NULL); 
	ptr = malloc(count * size); // Allocate memory for an array of ` count ` elements of ` size ` bytes each and assign the address of the allocated memory to the void pointer ptr.	
	if (ptr == NULL) // If the allocation fails, return NULL. 
		return (NULL);
	ft_bzero(ptr, count * size); // Set the allocated memory to zero.
	return (ptr);
}
