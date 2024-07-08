/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:26:14 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/16 20:12:36 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

typedef struct t_save
{
	char	**ptr;
}t_s;

void	get_input(t_list **stack, t_list **stack_b, t_s *a);
void	ra(t_list **stack_a);
void	rr(t_list **stack, t_list **stack_b);
void	check_dup(t_list *stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list *stack);
void	ss(t_list *stack, t_list *stack_b);
void	rra(t_list **stack);
void	rrr(t_list **stack, t_list **stack_b);
void	ft_free(char **str);
#endif