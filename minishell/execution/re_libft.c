/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:42:17 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/13 23:56:18 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "execution.h"

t_execute	*my_lstlast(t_execute *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

void	my_lstadd_back(t_execute **lst, t_execute *new)
{
	t_execute	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = my_lstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

t_execute	*my_lstnew(void *before, void *after)
{
	t_execute	*ptr;

	ptr = malloc(sizeof(t_execute));
	if (ptr == NULL)
		return (NULL);
	ptr->name = before;
	ptr->value = after;
	ptr->next = NULL;
	return (ptr);
}
