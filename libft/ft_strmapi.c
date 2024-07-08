/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:19:47 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/26 04:19:41 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) 
{ // This function applies the function f to each character of the string s to create a new string resulting from successive applications of f.
	unsigned int	i;
	char			*str;
 
	i = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1)); // Allocate memory for the new string.
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]); // Apply the function f to the current character of the string s and assign the result to the current character of the new string.
		i++;
	}
	str[i] = '\0'; // Add the null terminator to the end of the new string.
	return (str);
}
