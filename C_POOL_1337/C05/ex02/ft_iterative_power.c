/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:48:44 by abouzanb          #+#    #+#             */
/*   Updated: 2021/10/12 11:51:35 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	a;
	int	b;

	a = 1;
	b = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (a < power)
	{
		b = b * nb;
		a++;
	}
	return (b);
}
