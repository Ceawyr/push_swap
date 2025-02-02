/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:22:59 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/20 19:48:59 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_lstsize(t_list *node)
{
	size_t	i;

	i = 0;
	if (!node)
		return (0);
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
