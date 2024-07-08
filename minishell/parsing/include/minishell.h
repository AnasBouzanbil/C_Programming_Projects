/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:38:24 by hel-kadd          #+#    #+#             */
/*   Updated: 2023/04/18 01:30:00 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <ctype.h>
# include "../../execution/execution.h"

typedef struct s_token {
	enum {
		TOKEN_STR,
		TOKEN_EQUALS,
		TOKEN_LESS,
		TOKEN_GREATER,
		TOKEN_GREATGREATER,
		TOKEN_PIPE,
		TOKEN_SEMI,
		TOKEN_GP,
		TOKEN_DP,
		TOKEN_RED_INFILE,
		TOKEN_RED_OUTFILE,
		TOKEN_AND,
		TOKEN_ENV,
		TOKEN_HERE_DOC,
		TOKEN_NEW_LINE,
		TOKEN_SINGLE_QUOTE,
		TOKEN_DOUBLE_QUOTE,
		TOKEN_APEND,
		TOKEN_DOLLAR,
	} e_type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_var_quotes{
	int		i;
	int		s;
	int		double_quote;
	int		single_quote;
	char	*first;
	char	*sec;
	int		len;
	char	*var_name;
	char	*var_value;
	t_token	*current_token;
	t_token	*head;
	char	**str;
	t_file	*file;
}	t_var_quotes;

//token fuction
void		ft_add_back_token(t_token **list_token, t_token *new_token);
t_token		*initialize_tokens(char *value, int type);
// void		add_token(t_token **token, int type, char *value, int i, int s);
t_token		*lexer(char *input);
int			is_special_char(char c);
int			db_condition(char *input, int i, int count, int x);
int			sq_condition(char *input, int i, int count, int x);
char		*ft_strchr(const char *s, int c);
char		*ft_strndup(const char *s, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			is_charset(char c);
int			is_whitespace(char c);
t_file		*initialize_redirection(char *filename, char type, int a);
t_exeuction	*initialize_execution(char **str, t_file *file);
t_exeuction	*last_exec(t_exeuction *exec);
void		add_back_execution(t_exeuction **list_exec, t_exeuction *exec);
t_exeuction	*simple_exec_cmd(t_token *token);
t_exeuction	*filed_struct(char *input);
void		execution(t_exeuction *str);
void		add_back_file(t_file **list_file, t_file *file);
t_token		*expand_dollar(t_token **token1);
char		*ft_getenv(char *cmd);
void		rm_sng_quotes(t_token **head);
void		rm_db_quotes(t_token **head);
char		*ft_itoa(int a);
int			my_strcmp(const char *s1, const char *s2);
void		remove_quote(char *str, char c);
void		*free_token(t_token *token);
void		add_back_file(t_file **list_file, t_file *file);
void		remove_quotes23(char *str);
int			check_space(char *str);
void		ft_free_first_sec(char *sec, char *frist);
int			check_quotes(char c, int s, int q);
t_file		*last_file(t_file *head);
int			lexer_semi_pipe(t_token **token, int i, char *input);
int			lexer_redirection(t_token **token, int i, char *line);
int			the_strlen(char *str);
int			my(char c);
char		check_type_of_file(int type);
int			my_strcmp(const char *s1, const char *s2);
t_token		*token_is_file(t_token *token, t_file **file);
void		*my_malloc(size_t size, void *ptr, size_t old_size);
t_token		*token_in_string(t_exeuction **cmd, t_token *token);
int			check_error_first(t_token *curr);
int			check_synta_error_first(t_token *curr);

#endif