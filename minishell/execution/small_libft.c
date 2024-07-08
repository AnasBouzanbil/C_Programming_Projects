/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:36:28 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/11 17:45:18 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

size_t	my_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str && str[a] != '\0')
		a++;
	return (a);
}

char	*my_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(my_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*my_strjoin(char *str1, char *str2)
{
	int		lenth;
	int		lenth2;
	char	*ptr;

	ptr = (char *)malloc(sizeof(*ptr) * (my_strlen(str1)+ my_strlen(str2) + 1));
	if (ptr == NULL)
		return (NULL);
	lenth = 0;
	lenth2 = 0;
	while (str1 && str1[lenth] != '\0')
	{
		ptr[lenth] = str1[lenth];
		lenth++;
	}
	while (str2 && str2[lenth2] != '\0')
	{
		ptr[lenth] = str2[lenth2];
		lenth++;
		lenth2++;
	}
	ptr[lenth] = '\0';
	return (ptr);
}

char	*my_strchr(const char *str, int c)
{
	char	x;
	size_t	l;
	size_t	i;

	x = (char)c;
	i = 0;
	l = my_strlen(str);
	while (l >= i)
	{
		if (str[i] == x)
		{
			return ((char *)str + i);
		}
		i++;
	}
	return (0);
}

int	ft_lstsize(t_exeuction *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
