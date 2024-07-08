/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:11:32 by abouzanb          #+#    #+#             */
/*   Updated: 2023/01/25 22:33:31 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	check_av(t_list **stack, char **av)
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

int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*stack_b;
	t_s		a;

	a.ptr = ft_split("rra\n ra\n rb\n sa\n sb\n ss\n rr\n rrb\n rrr\n pa\n pb\n", ' ');
	if (ac == 1)
		return (0);
	check_av(&stack, av);
	get_input(&stack, &stack_b, &a);
}
