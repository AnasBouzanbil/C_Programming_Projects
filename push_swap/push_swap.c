/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:08:06 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/20 19:16:13 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap( t_list **satck_a, t_list **satck_b)
{
	if (ft_lstsize(*satck_a) <= 3)
		swap_three(satck_a);
	else if (ft_lstsize(*satck_a) <= 5)
		swap_five(satck_a, satck_b);
	else if (ft_lstsize(*satck_a) <= 100)
		ssorthunderd(satck_a, satck_b);
	else
		sortthousund(satck_a, satck_b);
}

void	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return ;
		i++;
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	help_filling(char *str)
{
	int	x;

	x = 0;
	if (!(ft_strlen(str) == 1) && (str[0] == '-' || str[0] == '+'))
		x++;
	while (str[x] != '\0')
	{
		if (ft_isdigit(str[x]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		x++;
	}
}

void	fill_stack(t_list **stack, char **av)
{
	int		i;
	char	**str;
	int		a;

	a = 0;
	i = 1;
	while (av[i])
	{
		check_space(av[i]);
		if (av[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		str = ft_split(av[i], ' ');
		a = 0;
		while (str[a])
		{
			help_filling(str[a]);
			ft_lstadd_back(stack, ft_lstnew(ft_atoi(str[a])));
			a++;
		}
		ft_free(str);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac == 1)
		exit(0);
	if (av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	fill_stack(&stack_a, av);
	check_dup(stack_a);
	is_sorted(stack_a, stack_b);
	push_swap(&stack_a, &stack_b);
}
