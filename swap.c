/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:58:47 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/16 00:48:17 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_sb_ss(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*stack = second;
}

void	sa(t_list **node)
{
	sa_sb_ss(node);
	write(1, "sa\n", 3);
}

void	sb(t_list **node)
{
	sa_sb_ss(node);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_sb_ss(stack_a);
	sa_sb_ss(stack_b);
	write(1, "ss\n", 3);
}
