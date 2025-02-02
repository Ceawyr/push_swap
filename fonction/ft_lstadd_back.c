/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:24:09 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/15 19:30:01 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return (1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->previous = last;
	new->next = NULL;
	return (0);
}
