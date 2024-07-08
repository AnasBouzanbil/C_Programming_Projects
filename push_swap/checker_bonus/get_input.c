/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:25:59 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/20 17:11:36 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_arg(char *str, t_s *a)
{
	int	i;

	i = 0;
	while (a->ptr[i])
	{
		if (ft_strncmp(str, a->ptr[i], ft_strlen(str)) == 0)
			return ;
		i++;
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	isit_sorted(t_list *stack_a, t_list *stack_b)
{
	int		x;
	t_list	*asta;

	if (stack_b != NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	while (stack_a)
	{
		x = stack_a->content;
		asta = stack_a;
		while (asta)
		{
			if (x > asta->content && stack_b == NULL)
			{
				write(1, "KO\n", 3);
				exit(0);
			}
			asta = asta->next;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	exit(0);
}

void	do_it(t_list **stack, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		rra(stack);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		rra(stack_b);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rr(stack, stack_b);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		ra(stack);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		ra(stack_b);
	else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		sa(*stack);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		sa(*stack_b);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		pa(stack, stack_b);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		pa(stack_b, stack);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ss(*stack, *stack_b);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rrr(stack, stack_b);
}

void	get_input(t_list **stack, t_list **stack_b, t_s *a)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_arg(str, a);
		do_it(stack, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	isit_sorted(*stack, *stack_b);
}
