/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:44 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/27 01:04:12 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_is_set(const char *set, char cut)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == cut)
			return (1);
		i++;
	}
	return (0);
}

static void	help_function(const char *s1, int i, int lenth, char *str)
{
	int	x;

	x = 0;
	while (s1[i] != '\0' && i < lenth)
	{
		str[x] = s1[i];
		i++;
		x++;
	}
	str[x] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		x;
	int		lenth;
	int		lenth2;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	lenth = ft_strlen(s1);
	x = 0;
	i = 0;
	lenth2 = lenth;
	while (check_is_set(set, s1[i]))
		i++;
	if (i == lenth)
		return (ft_strdup(""));
	while (check_is_set(set, s1[lenth - 1]))
		lenth--;
	str = (char *)malloc(sizeof(char) * ((lenth - i) + 1));
	if (str == NULL)
		return (NULL);
	help_function(s1, i, lenth, str);
	return (str);
}
