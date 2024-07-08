/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:46:17 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/18 01:23:10 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	add_back_file(t_file **list_file, t_file *file)
{
	t_file	*tmp;

	tmp = (*list_file);
	if (!(*list_file))
		(*list_file) = file;
	else
	{
		tmp = last_file((*list_file));
		tmp->next = file;
	}
}

char	check_type_of_file(int type)
{
	if (type == TOKEN_RED_OUTFILE)
		return ('O');
	if (type == TOKEN_RED_INFILE)
		return ('I');
	if (type == TOKEN_HERE_DOC)
		return ('H');
	if (type == TOKEN_APEND)
		return ('A');
	return ('N');
}

int	my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_token	*token_is_file(t_token *token, t_file **file)
{
	char	type;
	int		x;

	x = 0;
	if (token->next->e_type == TOKEN_STR)
		x = 1;
	type = check_type_of_file(token->e_type);
	if (token->next != NULL && token->next->e_type != TOKEN_PIPE)
		token = token->next;
	add_back_file(file, initialize_redirection(token->value, type, x));
		token = token->next;
	return (token);
}
