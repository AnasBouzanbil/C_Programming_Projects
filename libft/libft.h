/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:26:54 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/28 22:50:06 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this is the header file for the libft project

#ifndef LIBFT_H  //This is the header guard, it prevents the header from being included more than once.
# define LIBFT_H
# include <stdlib.h> //This is the standard library header file.
# include <unistd.h> //This is the header file that provides access to the POSIX operating system API.
# include <stdio.h> //This is the header file that provides access to the standard input and output streams.

typedef struct s_list //This is the structure of the linked list.
{
	void			*content; 
	struct s_list	*next; 

}t_list; 

int		ft_toupper(int a);
int		ft_tolower(int a);
int		ft_isprint(int c);
int		ft_isdigit(int a);
int		ft_isascii(int a);
int		ft_isupper(int a);
int		ft_isalpha(int a);
int		ft_isalnum(int a);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int k, int fd);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strnend(char *str, char *end);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t i);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *str, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstlast(t_list *lst);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int a);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memccpy(void *des, const void *sors, int stop, size_t n);
char	*ft_strrchr(const char *str, int c);
char	**ft_split(char *str, char cut);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(void *ptr, int value, size_t num);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);

#endif // LIBFT_H
