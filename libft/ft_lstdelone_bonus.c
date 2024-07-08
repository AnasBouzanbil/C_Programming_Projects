/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:57:09 by abouzanb          #+#    #+#             */
/*   Updated: 2022/10/27 00:51:53 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *)) // This function takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
