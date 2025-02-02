/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:48:51 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/17 02:21:31 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;

	if (!(*stack_b) || !stack_b)
		return ;
	head_b = *stack_b;
	*stack_b = head_b->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	head_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = head_b;
	head_b->previous = NULL;
	*stack_a = head_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;

	if (!(*stack_a) || !stack_a)
		return ;
	head_a = *stack_a;
	*stack_a = head_a->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	head_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = head_a;
	head_a->previous = NULL;
	*stack_b = head_a;
	write(1, "pb\n", 3);
}
