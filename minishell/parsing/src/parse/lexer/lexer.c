/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:21:09 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/17 23:51:06 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	lexer_is_word(t_token **token, char *input, int i, int s)
{
	int	count;
	int	single;

	s = i;
	count = 0;
	single = 0;
	while (input[i])
	{
		if (input[i] == 39 && count % 2 == 0)
			single++;
		if (input[i] == 34 && single % 2 == 0)
			count++;
		if (is_special_char(input[i]) == 0 && count % 2 == 0)
			break ;
		i++;
	}
	if ((count % 2 != 0 && single % 2 == 0)
		|| (count % 2 == 0 && single % 2 != 0))
	{
		printf("quotes not closed\n");
		return (-1);
	}
	ft_add_back_token(token,
		initialize_tokens(ft_strndup(input + s, i - s), TOKEN_STR));
	return (i);
}

int	double_quotes(t_token **token, char *input, int i, int s)
{
	int	count;
	int	x;

	s = i;
	i += 1;
	count = 1;
	x = 0;
	i = db_condition(input, i, count, x);
	if (i == -1)
		return (-1);
	ft_add_back_token(token,
		initialize_tokens(ft_strndup(input + s, i - s), TOKEN_DOUBLE_QUOTE));
	return (i);
}

int	single_quotes(t_token **token, char *input, int i, int s)
{
	int	count;
	int	x;

	s = i;
	count = 1;
	i += 1;
	x = 0;
	i = sq_condition(input, i, count, x);
	if (i == -1)
		return (-1);
	ft_add_back_token(token,
		initialize_tokens(ft_strndup(input + s, i - s), TOKEN_SINGLE_QUOTE));
	return (i);
}

int	spr(t_token **head, int i, char *input, int s)
{
	if ((input[i] == '<' || input[i] == '>'))
		i = lexer_redirection(head, i, input);
	if (input[i] == 39)
	{
		i = single_quotes(head, input, i, s);
	}
	if (input[i] == 34)
	{
		i = double_quotes(head, input, i, s);
	}
	return (i);
}

t_token	*lexer(char *input)
{
	t_var_quotes	v;

	v.i = 0;
	v.head = NULL;
	v.s = v.i;
	while (input[v.i])
	{
		if (is_special_char(input[v.i]) != 0 && \
		input[v.i] != 34 && input[v.i] != 39)
		{
			v.i = lexer_is_word(&v.head, input, v.i, v.s);
			if (v.i == -1)
				return (free_token(v.head));
		}
		if ((input[v.i] == '|' || input[v.i] == ';') && input[v.i] != ' ')
			v.i = lexer_semi_pipe(&v.head, v.i, input);
		else
			v.i = spr(&v.head, v.i, input, v.s);
		if (v.i == -1)
			return (free_token(v.head));
		if (the_strlen(input) <= v.i)
			break ;
		v.i++;
	}
	return (v.head);
}
