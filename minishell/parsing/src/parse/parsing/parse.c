/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:32:59 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/18 01:27:41 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_tokens(t_token *curr)
{
	if (curr->e_type == TOKEN_PIPE)
	{
		ft_put_error("mini: : syntax error near unexpected token `"\
		, curr->value, "'\n");
		g_data.exit_status = 258;
		return (-1);
	}
	while (curr)
	{
		if (curr->e_type == TOKEN_APEND || curr->e_type == TOKEN_RED_INFILE || \
		curr->e_type == TOKEN_HERE_DOC || curr->e_type == TOKEN_RED_OUTFILE || \
		curr->e_type == TOKEN_PIPE)
		{
			if (check_synta_error_first(curr) == -1)
				return (-1);
		}
		curr = curr->next;
	}
	return (0);
}

int	helper_check(t_token *current_token)
{
	if ((current_token->e_type == TOKEN_RED_INFILE
			|| current_token->e_type == TOKEN_RED_OUTFILE
			|| current_token->e_type == TOKEN_APEND)
		&& current_token->next != NULL
		&& current_token->next->value != NULL
		&& current_token->next->value[0] == '$'
		&& current_token->next->value[1] != '\0')
	{
		return (1);
	}
	return (0);
}

int	check_redirect_tokens(t_token *token_list)
{
	t_var_quotes	v;

	v.current_token = token_list;
	while (v.current_token != NULL)
	{
		if (helper_check(v.current_token) == 1)
		{
			v.var_name = &(v.current_token->next->value[1]);
			v.var_value = ft_getenv(v.var_name);
			if (v.var_value == NULL || v.var_value[0] == '\0'
				|| my_strchr(v.var_value, ' ') != NULL)
			{
				ft_putstr_fd("mini: ambiguous redirect\n ", 2);
				g_data.exit_status = 1;
				return (-1);
			}
		}
		v.current_token = v.current_token->next;
	}
	return (0);
}

void	*free_token(t_token *temp)
{
	t_token	*token;

	while (temp)
	{
		token = temp;
		temp = temp->next;
		free(token->value);
		free(token);
	}
	return (NULL);
}

t_exeuction	*filed_struct(char *input)
{
	t_token		*token;
	t_exeuction	*cmd;
	t_token		*temp;

	cmd = NULL;
	token = lexer(input);
	if (check_redirect_tokens(token) == -1)
		return (free_token(token));
	token = expand_dollar(&token);
	if (token == NULL)
		return (NULL);
	if (check_tokens(token) == -1)
		return (free_token(token));
	temp = token;
	while (token)
	{
		if (token->e_type != TOKEN_PIPE)
			token = token_in_string(&cmd, token);
		else
			token = token->next;
	}
	free_token(temp);
	if (!cmd)
		return (NULL);
	return (cmd);
}
