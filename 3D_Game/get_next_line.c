/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceddibao <ceddibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:41:16 by ceddibao          #+#    #+#             */
/*   Updated: 2023/04/09 22:39:00 by ceddibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/cub3d.h"

char	*get_bef(char *storage)
{
	int		i;
	char	*ret;

	i = 0;
	if (!ft_strchr(storage, '\n'))
		return (ft_strdup(storage));
	ret = (char *)malloc((ft_strlen(storage) + 1) * sizeof(char));
	while (storage[i])
	{
		if (storage[i] != '\n')
		{
			ret[i] = storage[i];
		}
		if (storage[i] == '\n')
		{
			ret[i] = storage[i];
			i++;
			break ;
		}
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*after_n(char *storage)
{
	char	*ret;
	int		i;

	i = 0;
	if (!ft_strchr(storage, '\n'))
		return (NULL);
	while (storage[i] != '\n')
		i++;
	ret = storage + i + 1;
	return (ft_strdup(ret));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*ret;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	tmp = NULL;
	if (!storage)
		storage = ft_strdup("");
	storage = read_from_fd(fd, storage);
	if (!storage)
		return (NULL);
	ret = get_bef(storage);
	tmp = after_n(storage);
	free (storage);
	storage = ft_strdup(tmp);
	free (tmp);
	return (ret);
}

char	*read_from_fd(int fd, char *storage)
{
	int		damana;
	char	*buff;
	char	*tmp;

	damana = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (damana && !ft_strchr(storage, '\n'))
	{
		damana = read(fd, buff, BUFFER_SIZE);
		if (damana == -1)
			return (free(buff), free(storage), NULL);
		if (damana == 0)
		{
			if (ft_strlen(storage) > 0)
				return (free(buff), storage);
			else
				return (free(storage), free(buff), NULL);
		}
		buff[damana] = '\0';
		tmp = ft_strjoin(storage, buff);
		storage = tmp;
	}
	return (free(buff), storage);
}
