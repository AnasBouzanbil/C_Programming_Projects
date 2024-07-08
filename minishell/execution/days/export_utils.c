/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:57 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:21:44 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	*the_full_value(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	if (i == 0)
		return (NULL);
	ptr = malloc((sizeof(char ) * i) + 2);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		ptr[i] = str[i];
		i++;
		if (str[i] == '=')
		{
			ptr[i] = str[i];
			i++;
			break ;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_help_is_valid_first(char *str)
{
	if (!str || str[0] == '\0')
	{
		ft_putstr_fd("bash: export: `': not a valid identifier\n", 2);
		g_data.exit_status = 1;
		free(str);
		return (0);
	}
	if (ft_isdigit(str[0]) == 1 || str[0] == '=')
	{
		ft_put_error("mini: export: `", str, "': not a valid identifier\n");
		g_data.exit_status = 1;
		free(str);
		return (0);
	}
	return (1);
}

int	ft_help_is_valid_second(char *str, int i)
{
	if (str && str[i] == '+')
	{
		if (str[i + 1] != '=')
		{
			ft_put_error("mini: export: `", \
			str, "': not a valid identifier\n");
			g_data.exit_status = 1;
			free(str);
			return (0);
		}
	}
	if (ft_isalnum(str[i]) == 0 && str[i] != '+' && str[i] != '_')
	{
		ft_put_error("bash: export: `", str, "': not a valid identifier\n");
		g_data.exit_status = 1;
		free(str);
		return (0);
	}
	return (1);
}

int	is_valid(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = the_full_value(ptr);
	if (ft_help_is_valid_first(str) == 0)
		return (0);
	while (str && str[i])
	{
		if (str[i] == '=')
		{
			free(str);
			return (1);
		}
		if (ft_help_is_valid_second(str, i) == 0)
			return (0);
		i++;
	}
	free(str);
	return (1);
}
