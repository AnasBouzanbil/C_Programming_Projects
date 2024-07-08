/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:22:11 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/16 15:29:01 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	remove_quotes23_helper(char *str, int len,
int *inside_single_quotes, int *inside_double_quotes)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '"' && !(*inside_single_quotes))
		{
			*inside_double_quotes = !(*inside_double_quotes);
			i++;
		}
		else if (str[i] == '\'' && !(*inside_double_quotes))
		{
			*inside_single_quotes = !(*inside_single_quotes);
			i++;
		}
		else if (str[i] == '"' && (*inside_single_quotes))
			i++;
		else if (str[i] == '\'' && (*inside_double_quotes))
			i++;
		else
			i++;
	}
}

void	remove_quotes23(char *str)
{
	t_var_quotes	v;
	int				j;

	v.len = ft_strlen(str);
	v.single_quote = 0;
	v.double_quote = 0;
	remove_quotes23_helper(str, v.len, &v.single_quote, &v.double_quote);
	j = 0;
	v.i = 0;
	while (v.i < v.len)
	{
		if (str[v.i] == '"' && !v.single_quote)
			v.double_quote = !v.double_quote;
		else if (str[v.i] == '\'' && !v.double_quote)
			v.single_quote = !v.single_quote;
		else if (str[v.i] == '"' && v.single_quote)
			str[j++] = '"';
		else if (str[v.i] == '\'' && v.double_quote)
			str[j++] = '\'';
		else
			str[j++] = str[v.i];
		v.i++;
	}
	str[j] = '\0';
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_first_sec(char *sec, char *frist)
{
	free(frist);
	free(sec);
}

int	check_quotes(char c, int s, int q)
{
	if (c == 34 && s % 2 == 0)
	{
		q += 1;
		return (q);
	}
	return (q);
}
