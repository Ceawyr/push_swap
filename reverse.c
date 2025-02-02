/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:30:04 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/31 03:00:36 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_list **stack)
{
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	if (last_node->previous)
		last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->next = *stack;
	(*stack)->previous = last_node;
	*stack = last_node;
}

void	rra(t_list **stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}
