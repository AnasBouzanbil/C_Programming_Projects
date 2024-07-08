/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:12:24 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/14 14:59:08 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helpf(int a, int b, int c, t_list **stack_a)
{
	if (a > b && a < c && b < c)
		sa(*stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && c < a)
		rra(stack_a);
	else if (a > c && b > c && a > c)
	{
		ra(stack_a);
		sa(*stack_a);
	}
}

void	swap_three(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;

	if (ft_lstsize(*stack_a) == 2)
	{
		sa(*stack_a);
		exit(0);
	}
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	helpf(a, b, c, stack_a);
}
