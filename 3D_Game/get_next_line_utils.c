/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceddibao <ceddibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:42:13 by ceddibao          #+#    #+#             */
/*   Updated: 2023/04/09 22:42:27 by ceddibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/cub3d.h"

void	ft_bzero(void *s, int n)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		last;
	char	*ret;

	i = 0;
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ret == NULL)
		return (ret);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	last = i;
	i = 0;
	while (s2[i])
	{
		ret[last] = s2[i];
		i++;
		last++;
	}
	ret[last] = '\0';
	ft_bzero((char *)s2, 5);
	free((char *)s1);
	return (ret);
}

char	*ft_strchr(char *str, int c)
{
	int	slen;
	int	i;

	i = 0;
	slen = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	if (c == 0)
		return ((char *)(str + slen));
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	int		l;
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	l = ft_strlen(s) + 1;
	i = 0;
	dup = (char *) malloc(l * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
