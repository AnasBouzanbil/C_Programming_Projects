/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:50:39 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/11 20:17:01 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*stack;
	t_list	*temp;	

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	stack = ft_lstlast(temp);
	stack->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_a)
{
	t_list	*stack;
	t_list	*temp;	

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	stack = ft_lstlast(temp);
	stack->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack, t_list **stack_b)
{
	ra(stack);
	rb(stack_b);
}
