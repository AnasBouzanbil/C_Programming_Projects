/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:38:18 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/15 20:29:16 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int		x;
	t_list	*asta;

	if (stack_b != NULL)
		return (1);
	while (stack_a)
	{
		x = stack_a->content;
		asta = stack_a;
		while (asta)
		{
			if (x > asta->content && stack_b == NULL)
				return (1);
			asta = asta->next;
		}
		stack_a = stack_a->next;
	}
	exit(0);
}

void	minihelp(t_list **stack_a, int *i, int *size)
{
	rra(stack_a);
	(*i)--;
	(*size)--;
}
