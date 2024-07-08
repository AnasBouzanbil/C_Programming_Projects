/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_and_free_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:30:06 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 21:28:19 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	free_node(t_exeuction *str)
{
	t_file		*file;
	t_exeuction	*temp;
	t_file		*temp2;

	while (str)
	{
		file = str->file;
		while (file)
		{
			free(file->name);
			temp2 = file;
			file = file->next;
			temp2->next = NULL;
			free(temp2);
		}
		ft_free(str->str);
		temp = str;
		str = str->next;
		free(temp);
	}
	free(str);
}

void	check_the_path(t_exeuction *str, t_va *av, char **path)
{
	int	i;

	i = 0;
	while (path && path[i])
	{
		av->comd = my_strjoin(path[i], str->str[0]);
		if (access(av->comd, X_OK) == 0)
			return ;
		i++;
		free(av->comd);
	}
	av->comd = NULL;
}

void	is_directory(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL && my_strchr(path, '/') && my_strcmp(path, ".."))
	{
		closedir(dir);
		ft_put_error("mini: ", path, ": is a directory\n");
		exit (126);
	}
	else if (dir != NULL)
	{
		closedir(dir);
		ft_put_error("mini: ", path, ": command not found\n");
		exit (127);
	}
}

int	ft_functioon_help_get_path(t_exeuction *str, t_va *av)
{
	is_directory(str->str[0]);
	if ((access(str->str[0], X_OK) == 0))
	{
		av->comd = str->str[0];
		return (1);
	}
	if (my_strchr(str->str[0], '/') && access(str->str[0], F_OK) == 0)
	{
		ft_put_error("mini: ", str->str[0], ": Permission denied\n");
		exit(126);
	}
	if (my_strchr(str->str[0], '/'))
	{
		ft_put_error("mini: ", str->str[0], ": No such file or directory\n");
		exit(127);
	}
	return (0);
}

void	get_path(t_exeuction *str, t_va *av)
{
	t_execute	*tmp;
	char		**path;

	if (ft_functioon_help_get_path(str, av) == 1)
		return ;
	tmp = g_data.str;
	if (tmp == NULL)
	{
		av->comd = NULL;
		return ;
	}
	path = NULL;
	while (tmp)
	{
		if (tmp->name && strcmp(tmp->name, "PATH=") == 0)
			path = ft_split_with_slash(tmp->value, ':');
		tmp = tmp->next;
	}
	if (path == NULL)
	{
		av->comd = NULL;
		return ;
	}
	check_the_path(str, av, path);
}
