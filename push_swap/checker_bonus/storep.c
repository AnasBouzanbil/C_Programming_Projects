/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:06:31 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/25 22:37:12 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	rr(t_list **stack, t_list **stack_b)
{
	ra(stack);
	ra(stack_b);
}
