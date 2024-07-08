/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:28:43 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:28:51 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	cont_size_off_the_name(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (str[i] == '+')
			i++;
		else
		{
			x++;
			i++;
		}
	}
	return (x);
}

char	*the_name(char *str)
{
	int		i;
	int		x;
	char	*ptr;

	i = 0;
	x = cont_size_off_the_name(str);
	ptr = malloc((sizeof(char ) * x + 3));
	x = 0;
	i = 0;
	while (str[i])
	{
		ptr[x++] = str[i++];
		if (str[i] == '+')
			i++;
		if (str[i] == '=')
		{
			ptr[x] = str[i];
			x++;
			break ;
		}
	}
	ptr[x] = '\0';
	return (ptr);
}

char	*the_value(char *str)
{
	char	*ptr;
	int		i;
	int		a;
	int		x;

	x = 0;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	a = i;
	while (str[a])
		a++;
	ptr = malloc((sizeof(char ) * a + 1));
	if (ptr == NULL)
		return (NULL);
	i++;
	while (str[i])
		ptr[x++] = str[i++];
	ptr[x] = '\0';
	return (ptr);
}
