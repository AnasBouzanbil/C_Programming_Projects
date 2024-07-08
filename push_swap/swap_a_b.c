/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:46:02 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/16 20:13:22 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	i = stack->content;
	stack->content = stack->next->content;
	stack->next->content = i;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	i = stack->content;
	stack->content = stack->next->content;
	stack->next->content = i;
	write(1, "sb\n", 3);
}
