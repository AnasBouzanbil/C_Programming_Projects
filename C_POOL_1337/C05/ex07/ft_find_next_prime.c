/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:14:40 by abouzanb          #+#    #+#             */
/*   Updated: 2021/10/14 15:29:28 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
	{
		return (2);
	}
	if (nb == 2147483647)
	{
		return (nb);
	}
	while (i <= (nb / i))
	{
		if ((nb % i) == 0)
		{
			return (ft_find_next_prime(nb + 1));
		}
		i++;
	}
	return (nb);
}
