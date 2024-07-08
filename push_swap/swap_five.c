/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:09:06 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/20 19:14:38 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_biggest(t_list *stack)
{
	int	temp;
	int	position;
	int	current_position;

	temp = stack->content;
	position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->content > temp)
		{
			temp = stack->content;
			position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (position + 1);
}

int	thelower(t_list *stack)
{
	int	temp;
	int	position;
	int	current_position;

	temp = stack->content;
	position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->content < temp)
		{
			temp = stack->content;
			position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (position);
}

void	swap_five(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		size = ft_lstsize(*stack_a);
		index = thelower(*stack_a);
		if (index == 0)
		{
			pb(stack_a, stack_b);
			continue ;
		}
		if (index > size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	swap_three(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}
