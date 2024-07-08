/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:00:59 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/16 20:10:58 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	t_list	*last;
	t_list	*take;

	if (!(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	take = *stack;
	while (take)
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
	write(1, "rrb\n", 4);
}

int	suee_function(t_list **stack_a, t_list **stack_b, int i)
{
	int	j;

	if ((i == 0 || (*stack_a && \
		(*stack_b)->content > ft_lstlast(*stack_a)->content)))
	{
		pa(stack_b, stack_a);
		ra(stack_a);
		i++;
	}
	else
	{
		j = the_biggest(*stack_b);
		if (j < ft_lstsize(*stack_b) / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	return (i);
}
