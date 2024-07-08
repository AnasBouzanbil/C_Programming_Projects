/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:33:06 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 00:32:48 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	count(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_pwd(void)
{
	char	str[PATH_MAX];

	getcwd(str, sizeof(str));
	printf("%s\n", str);
	g_data.exit_status = 0;
}

int	equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_put_error(char *str, char *str1, char *str2)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
}
