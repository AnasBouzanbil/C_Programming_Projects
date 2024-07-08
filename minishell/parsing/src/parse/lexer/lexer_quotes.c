/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:13:13 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/17 16:55:18 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	db_condition(char *input, int i, int count, int x)
{
	while (input[i] != '\0')
	{
		if (input[i] == 34)
			count++;
		if (input[i] == 39 && count % 2 == 0)
			x++;
		if ((input[i] == 34 && input[i + 1] == ' '))
		{
			i++;
			break ;
		}
		if (input[i] == ' ' && count % 2 == 0 && x % 2 == 0)
			break ;
		i++;
	}
	if ((count % 2 != 0 && x % 2 == 0) || (x % 2 != 0 && count % 2 == 0))
	{
		printf("quotes not closed\n");
		return (-1);
	}
	return (i);
}

int	sq_condition(char *input, int i, int count, int x)
{
	while (input[i] != '\0')
	{
		if (input[i] == 34 && count % 2 == 0)
			x++;
		if (input[i] == 39)
			count++;
		if (input[i] == 39 && (input[i + 1] == ' '))
		{
			i++;
			break ;
		}
		if (input[i] == ' ' && count % 2 == 0 && x % 2 == 0)
			break ;
		i++;
	}
	if ((count % 2 != 0 && x % 2 == 0) || (x % 2 != 0 && count % 2 == 0))
	{
		printf("quotes not closed\n");
		return (-1);
	}
	return (i);
}

int	lexer_semi_pipe(t_token **token, int i, char *input)
{
	if (input[i] == ';')
		ft_add_back_token(token,
			initialize_tokens(ft_strndup(input + i, 1), TOKEN_SEMI));
	if (input[i] == '|')
		ft_add_back_token(token,
			initialize_tokens(ft_strndup(input + i, 1), TOKEN_PIPE));
	return (i);
}

int	lexer_redirection(t_token **token, int i, char *line)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
		{
			ft_add_back_token(token, initialize_tokens
				(ft_strndup(line + i, 2), TOKEN_HERE_DOC));
			i++;
		}
		else
			ft_add_back_token(token,
				initialize_tokens(ft_strndup(line + i, 1), TOKEN_RED_INFILE));
	}
	else
	{
		if (line[i + 1] == '>')
		{
			ft_add_back_token(token,
				initialize_tokens(ft_strndup(line + i, 2), TOKEN_APEND));
			i++;
		}
		else
			ft_add_back_token(token,
				initialize_tokens(ft_strndup(line + i, 1), TOKEN_RED_OUTFILE));
	}
	return (i);
}
