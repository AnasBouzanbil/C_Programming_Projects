/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comand_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:26:52 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/27 16:49:11 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*help_is_valid(char **cmd1, char **path)
{
	int		i;
	char	*test;

	i = 0;
	while (path[i])
	{
		test = ft_strjoin(path[i], cmd1[0]);
		if (access(test, X_OK) == 0)
		{
			ft_free(path);
			ft_free(cmd1);
			return (test);
		}
		free(test);
		i++;
	}
	ft_free(path);
	ft_free(cmd1);
	return (0);
}

char	*is_valid(char *cmd, char **env)
{
	char	**cmd1;
	char	**path;
	int		i;

	i = 0;
	cmd1 = ft_split(cmd, ' ');
	if (access(cmd1[0], X_OK) == 0)
		return (cmd1[0]);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split_with_slash(env[i] + 5, ':');
		}
		i++;
	}
	return (help_is_valid(cmd1, path));
}
