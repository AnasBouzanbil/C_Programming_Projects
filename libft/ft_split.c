/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:31:41 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/27 01:18:29 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strings_count(char *str, char split)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == split)
		i++;
	while (str[i])
	{
		if (str[i] != split && (str[i + 1] == split || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	helper_function(int x, char cut, char *str, char **ptr)
{
	int	l;
	int	i;
	int	count;

	i = 0;
	count = strings_count(str, cut); // Count the number of strings in the string.
	while (x < count) // Iterate through the array of pointers to strings.
	{
		while (str[i] == cut && str[i] != '\0') // Skip the delimiters. 
		{ 
			i++; // count the number of delimiters. 
		}
		if (str[i] != cut && str[i]) // If the current character is not a delimiter and not the end of the string, we found a string.
		{
			l = i; // Set the counter l to the current index. 
			while (str[l] != cut && str[l]) // Iterate through the string until we reach a delimiter or the end of the string.
				l++; 
			ptr[x] = ft_substr(str, i, (l - i)); // Allocate memory for the string and assign the address of the allocated memory to the current pointer of the array of pointers.
			x++;
		}
		while (str[i] && str[i] != cut)
			i++;
	}
}

char	**ft_split(char *str, char cut) // ` ft_split ` splits a string into an array of strings using the character ` cut ` as a delimiter.
{ // The function returns a pointer to the array of strings.
	int		x;
	int		count;
	char	**ptr;

	x = 0;
	if (str == NULL) // If the string is NULL, return NULL. 
		return (NULL); // we can't split a NULL string. so we return NULL.
	count = strings_count(str, cut);  // Count the number of strings in the string.
	ptr = (char **)malloc(sizeof(char *) * (count + 1)); // Allocate memory for an array of pointers to strings. The number of pointers is equal to the number of strings + 1. The +1 is for the NULL pointer at the end of the array.
	if (ptr == NULL) // If the allocation fails, return NULL.
		return (NULL); // We can't split the string if we can't allocate memory for the array of pointers. So we return NULL.
	ptr[count] = NULL; // we set the last pointer of the array to NULL. 
	helper_function(x, cut, str, ptr); // We call the helper function to fill the array of pointers with the strings.
	return (ptr);
}
