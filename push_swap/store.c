/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:26:36 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/14 23:05:27 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_inndex(int start, int end, t_list *stac)
{
	int	x;

	x = 0;
	while (stac)
	{
		if (stac->content >= start && stac->content <= end)
			return (x);
		x++;
		stac = stac->next;
	}
	return (-1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	isthere(t_list *stack, int a)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == a)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	less_push(int i, t_num *n, t_list **stack, t_list **stack_b)
{
	while (i > 0)
	{
		ra(stack);
		i--;
	}
	pb(stack, stack_b);
	if ((*stack_b)->content < n->arr[n->mid])
		rb(stack_b);
	n->size--;
}

void	check_dup(t_list *stack)
{
	t_list	*temp;
	int		tem;
	int		rang;

	while (stack)
	{
		rang = 0;
		temp = stack;
		tem = stack->content;
		while (temp)
		{
			if (tem == temp->content)
				rang++;
			temp = temp->next;
		}
		if (rang == 2)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		stack = stack->next;
	}
}
