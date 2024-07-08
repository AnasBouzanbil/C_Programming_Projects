/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:17:16 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 21:18:24 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_env(void)
{
	t_execute	*temp;

	temp = g_data.str;
	while (temp)
	{
		if (my_strchr(temp->name, '=') != NULL)
		{
			ft_putstr_fd(temp->name, 1);
			if (temp->value != NULL)
				ft_putstr_fd(temp->value, 1);
			ft_putstr_fd("\n", 1);
		}
		temp = temp->next;
	}
	g_data.exit_status = 0;
}

char	*name_without_equal(char *str)
{
	int		i;
	int		x;
	char	*ptr;

	i = 0;
	x = 0;
	while (str && str[i] && str[i] != '=' && str[i] != '+')
		i++;
	if (i == 0)
		return (NULL);
	ptr = ft_calloc((sizeof(char ) * i + 1), 1);
	while (str[x] && x < i)
	{
		ptr[x] = str[x];
		x++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_getenv(char *cmd)
{
	t_execute	*temp;
	char		*st;

	temp = g_data.str;
	while (temp)
	{
		st = name_without_equal(temp->name);
		if (my_strcmp(st, cmd) == 0)
		{
			free(st);
			return (temp->value);
		}
		free(st);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_cd(char **cmd)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = getcwd(NULL, 0);
	if (ft_count(cmd) == 1)
	{
		if (chdir(ft_getenv("HOME")) == -1)
		{
			ft_putstr_fd("mini: cd: HOME not set\n", 2);
			g_data.exit_status = 1;
		}
		chnage_old_pwd(pwd);
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			ft_put_error("mini: cd: ", cmd[1], ": No such file or directory\n");
			g_data.exit_status = 1;
		}
		chnage_old_pwd(pwd);
	}
}

void	ft_echo(char **str)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	if (count(str) > 1)
	{
		while (str[i] && str[i][0] && is_no(str[i]) == 0)
		{
			x++;
			i++;
		}
		while (str[i])
		{
			printf("%s", str[i]);
			if (str[i + 1])
				printf(" ");
			i++;
		}
	}
	if (x == 0)
		printf("\n");
	g_data.exit_status = 0;
}
