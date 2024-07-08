/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:12 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/17 20:46:52 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_special_char(char c)
{
	if (!ft_strchr("><|; \t", c))
		return (1);
	return (0);
}

int	ft_redirection(t_token *token)
{
	if (token->value[0] != '<' && token->value[0] != '>')
		return (0);
	return (1);
}

int	is_charset(char c)
{
	if (c == 39 || c == 34 || c == '<' || c == '>' || c == '|'
		|| c == '$' || is_whitespace(c) || c == '\n' || c == '\0')
		return (1);
	return (0);
}
