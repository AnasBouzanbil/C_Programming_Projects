/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:30:45 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/18 01:07:21 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*expand_env(char *dollar)
{
	int		j;
	char	*var_name;
	char	*var_value;
	char	*expanded;

	j = 0;
	expanded = NULL;
	if (dollar[j++] == '?')
		expanded = ft_itoa(g_data.exit_status);
	else
	{
		while (dollar[j] && (dollar[j] == '_' || ft_isalnum(dollar[j])))
			j++;
		var_name = ft_strndup(dollar, j);
		var_value = ft_getenv(var_name);
		free(var_name);
		if (var_value)
			expanded = ft_strdup(var_value);
	}
	var_value = expanded;
	expanded = ft_strjoin(expanded, dollar + j);
	free(var_value);
	return (expanded);
}

char	*expand_double(char *str, int *a)
{
	t_var_quotes	v;

	v.i = -1;
	v.double_quote = 0;
	v.single_quote = 0;
	while (str[++v.i])
	{
		v.double_quote = check_quotes(str[v.i], v.single_quote, v.double_quote);
		if (str[v.i] == 39 && v.double_quote % 2 == 0)
			v.single_quote += 1;
		if ((str[v.i] == '$' && my(str[v.i + 1]) && ((v.double_quote % 2 != 0)
					|| (v.double_quote % 2 == 0 && v.single_quote % 2 == 0))))
		{
			*a = 1;
			v.first = ft_strndup(str, v.i);
			if (my_strcmp(str + v.i, "$") == 0)
				v.sec = ft_strdup(str + v.i);
			else
				v.sec = expand_env(str + v.i + 1);
			str = ft_strjoin(v.first, v.sec);
			ft_free_first_sec(v.sec, v.first);
			return (str);
		}
	}
	return (str);
}

int	count_dollar(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}

char	*expand_do(char *str)
{
	int		u;
	char	*temp;
	int		a;

	temp = NULL;
	u = count_dollar(str);
	a = 0;
	while (ft_strchr(str, '$') && u > 0)
	{
		temp = str;
		str = expand_double(str, &a);
		if (u != 0 && a == 1)
			free(temp);
		u--;
		a = 0;
	}
	remove_quotes23(str);
	return (str);
}

t_token	*expand_dollar(t_token **token)
{
	t_token	*temp;
	int		here_doc;

	here_doc = 1;
	temp = (*token);
	while (temp)
	{
		if (temp->e_type == TOKEN_PIPE)
			g_data.exit_status = 0;
		if (here_doc && temp->e_type != TOKEN_SINGLE_QUOTE
			&& temp->e_type != TOKEN_DOUBLE_QUOTE)
			temp->value = expand_do(temp->value);
		if (temp->e_type == TOKEN_DOUBLE_QUOTE)
			temp->value = expand_do(temp->value);
		if (temp->e_type == TOKEN_SINGLE_QUOTE)
			temp->value = expand_do(temp->value);
		if (temp->e_type == TOKEN_HERE_DOC)
			here_doc = 0;
		else
			here_doc = 1;
		temp = temp->next;
	}
	return (*token);
}
