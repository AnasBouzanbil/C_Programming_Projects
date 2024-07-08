/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:26:26 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/18 01:28:05 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	*my_malloc(size_t size, void *ptr, size_t old_size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(size);
	}
	else if (size <= old_size)
	{
		new_ptr = ptr;
	}
	else
	{
		new_ptr = malloc(size);
		if (new_ptr != NULL)
		{
			memcpy(new_ptr, ptr, old_size);
			free(ptr);
		}
	}
	return (new_ptr);
}

t_token	*token_in_string(t_exeuction **cmd, t_token *token)
{
	t_var_quotes	v;

	v.i = 0;
	v.str = my_malloc(sizeof(char *), NULL, 0);
	v.str[v.i] = NULL;
	v.file = NULL;
	while (token != NULL && token->e_type != TOKEN_PIPE)
	{
		if (token->e_type == TOKEN_HERE_DOC || token->e_type == TOKEN_RED_INFILE
			|| token->e_type == TOKEN_RED_OUTFILE
			||token->e_type == TOKEN_APEND)
			token = token_is_file(token, &v.file);
		else
		{
			v.str = my_malloc((v.i + 1) * sizeof(char *),
					v.str, v.i * sizeof(char *));
			v.str[v.i] = ft_strdup(token->value);
			v.i++;
			token = token->next;
		}
	}
	v.str = my_malloc((v.i + 1) * sizeof(char *), v.str, v.i * sizeof(char *));
	v.str[v.i] = NULL;
	add_back_execution(cmd, initialize_execution(v.str, v.file));
	return (token);
}

int	check_error_first(t_token *curr)
{
	if (curr->e_type == TOKEN_APEND || \
	curr->e_type == TOKEN_RED_INFILE \
	|| curr->e_type == TOKEN_HERE_DOC || \
	curr->e_type == TOKEN_RED_OUTFILE)
	{
		if (curr->next->e_type != TOKEN_DOUBLE_QUOTE \
		&& curr->next->e_type != TOKEN_STR \
			&& curr->next->e_type != TOKEN_SINGLE_QUOTE)
		{
			ft_put_error("mini: : syntax error near unexpected token `", \
			curr->value, "'\n");
			g_data.exit_status = 258;
			return (-1);
		}
	}
	return (0);
}

int	check_synta_error_first(t_token *curr)
{
	if (!curr->next)
	{
		ft_putstr_fd("mini: : syntax error near unexpected token `newline'\n"\
		, 2);
		g_data.exit_status = 258;
		return (-1);
	}
	if (check_error_first(curr) == -1)
		return (-1);
	if (curr->e_type == TOKEN_PIPE)
	{
		if (curr->next->e_type == TOKEN_PIPE)
		{
			ft_put_error("mini: : syntax error near unexpected token `", \
			curr->value, "'\n");
			g_data.exit_status = 258;
			return (-1);
		}
	}
	return (0);
}
