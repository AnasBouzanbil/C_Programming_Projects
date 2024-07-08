/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:34:51 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/14 19:27:47 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_nswap(int *arr, int i)
{
	int	x;
	int	j;
	int	temp;

	j = 0;
	while (j < i - 1)
	{
		x = 0;
		while (x < i - 1)
		{
			if (arr[x] > arr[x + 1])
			{
				temp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
			}
			x++;
		}
		j++;
	}
}

int	*nswap(t_list *stack)
{
	int	*arr;
	int	i;

	arr = malloc(ft_lstsize(stack) * (sizeof(int)));
	i = 0;
	while (stack)
	{
		arr[i] = stack->content;
		i++;
		stack = stack->next;
	}
	help_nswap(arr, i);
	return (arr);
}

void	more_push(int i, t_num *n, t_list **stack, t_list **stack_b)
{
	while (i <= n->size)
	{
		rra(stack);
		i++;
	}
	pb(stack, stack_b);
	if ((*stack_b)->content < n->arr[n->mid])
		rb(stack_b);
	n->size--;
}
