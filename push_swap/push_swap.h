/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:20:45 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/20 16:58:27 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;
typedef struct s_num
{
	int	i;
	int	offset;
	int	start;
	int	mid;
	int	end;
	int	x;
	int	size;
	int	*arr;
}t_num;

void	sa(t_list *stack);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	sb(t_list *stack);
int		ft_atoi(const char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	rra(t_list **stack);
void	rrr(t_list **stack, t_list **stack_b);
void	rrb(t_list **stack);
void	ra(t_list **stack_a);
void	rr(t_list **stack, t_list **stack_b);
void	rb(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	swap_three(t_list **stack);
int		is_sorted(t_list *stack_a, t_list *stack_b);
int		the_biggest(t_list *stack);
int		thelower(t_list *stack);
void	swap_five(t_list **stack_a, t_list **stack_b);
int		*nswap(t_list *swap);
int		get_inndex(int start, int end, t_list *stac);
int		isthere(t_list *stack, int a);
void	minihelp(t_list **stack_a, int *i, int *size);
void	to_stacka(t_list **stack_a, t_list **stack_b, int *arr);
void	less_push(int i, t_num *n, t_list **stack, t_list **stack_b);
void	more_push(int i, t_num *n, t_list **stack, t_list **stack_b);
void	change_range(t_num *n);
size_t	ft_strlen(const char *str);
char	**ft_split(char *str, char cut);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_isdigit(char a);
void	check_dup(t_list *stack);
void	ss(t_list *stack, t_list *stack_b);
void	ft_free(char **str);
int		suee_function(t_list **stack_a, t_list **stack_b, int i);
void	sortthousund(t_list **stack, t_list **stack_b);
void	ssorthunderd(t_list **stack, t_list **stack_b);
void	change_range(t_num *n);
#endif