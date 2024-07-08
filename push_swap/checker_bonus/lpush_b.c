/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpush_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:25:30 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/25 22:33:54 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp);
}

void	sa(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	i = stack->content;
	stack->content = stack->next->content;
	stack->next->content = i;
}

void	ss(t_list *stack, t_list *stack_b)
{
	sa(stack);
	sa(stack_b);
}

void	rra(t_list **stack)
{
	t_list	*last;
	t_list	*take;

	last = ft_lstlast(*stack);
	take = *stack;
	while (take && take->next)
	{
		if (take->next->next == NULL)
		{
			take->next = NULL;
			break ;
		}
		take = take->next;
	}
	ft_lstadd_front(stack, last);
	take = NULL;
}

void	rrr(t_list **stack, t_list **stack_b)
{
	rra(stack);
	rra(stack_b);
}
