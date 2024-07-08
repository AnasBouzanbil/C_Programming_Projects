/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:20:26 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/25 22:32:34 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_stacka(t_list **stack_a, t_list **stack_b, int *arr)
{
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(*stack_b) - 1;
	while (*stack_b || size >= 0)
	{
		if (isthere(*stack_b, arr[size]) >= 0)
		{
			if ((*stack_b)->content == arr[size])
			{
				pa(stack_b, stack_a);
				size--;
			}
			else
				i = suee_function(stack_a, stack_b, i);
		}
		else
			minihelp(stack_a, &i, &size);
	}
	exit(0);
}

void	check_range_is_valid(t_num *n)
{
	if (n->start < 0)
		n->start = 0;
	if (n->end > n->size)
		n->size = *(n->arr) - 1;
}

int	isthee(int i, int *arr, int start, int end)
{
	while (start <= end)
	{
		if (i == arr[start])
			return (1);
		start++;
	}
	return (0);
}

void	ssorthunderd(t_list **stack, t_list **stack_b)
{
	t_num	n;

	n.size = ft_lstsize(*stack);
	n.mid = (n.size / 2) - 1;
	n.offset = 30;
	n.start = n.mid - n.offset;
	n.end = n.mid + n.offset;
	n.arr = nswap(*stack);
	check_range_is_valid(&n);
	while (*stack)
	{
		if (isthee((*stack)->content, n.arr, n.start, n.end))
		{
			pb(stack, stack_b);
			if ((*stack_b)->content < n.arr[n.mid])
				rb(stack_b);
		}
		else
			ra(stack);
		if (ft_lstsize(*stack_b) >= n.end - n.start + 1)
			change_range(&n);
	}
	to_stacka(stack, stack_b, n.arr);
}

void	sortthousund(t_list **stack, t_list **stack_b)
{
	t_num	n;

	n.size = ft_lstsize(*stack);
	n.mid = (n.size / 2) - 1;
	n.offset = 65;
	n.start = n.mid - n.offset;
	n.end = n.mid + n.offset;
	n.arr = nswap(*stack);
	check_range_is_valid(&n);
	while (*stack)
	{
		if (isthee((*stack)->content, n.arr, n.start, n.end))
		{
			pb(stack, stack_b);
			if ((*stack_b)->content < n.arr[n.mid])
				rb(stack_b);
		}
		else
			ra(stack);
		if (ft_lstsize(*stack_b) >= (n.end - n.start) + 1)
			change_range(&n);
	}
	to_stacka(stack, stack_b, n.arr);
}
