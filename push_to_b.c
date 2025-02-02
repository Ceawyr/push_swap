/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:10:38 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:28:14 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheap_push(t_list **stack)
{
	t_list	*node;
	t_list	*best_to_move;
	int		mini;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	mini = node->push_cost;
	best_to_move = node;
	while (node)
	{
		if (node->push_cost == 0)
			return (node);
		if (node->push_cost < mini)
		{
			mini = node->push_cost;
			best_to_move = node;
		}
		node = node->next;
	}
	return (best_to_move);
}

void	align_both_mzero(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_a);
	target = node->target;
	while (node != *stack_a && target != *stack_b)
		rr(stack_a, stack_b);
	while (node != *stack_a)
		ra(stack_a);
	while (target != *stack_b)
		rb(stack_b);
}

void	align_both_mone(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_a);
	target = node->target;
	while (node != *stack_a && target != *stack_b)
		rrr(stack_a, stack_b);
	while (node != *stack_a)
		rra(stack_a);
	while (target != *stack_b)
		rrb(stack_b);
}

void	align_diff_m(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_a);
	target = node->target;
	if (node->median == 0 && target->median == 1)
	{
		while (node != *stack_a)
			ra(stack_a);
		while (target != *stack_b)
			rrb(stack_b);
	}
	else
	{
		while (node != *stack_a)
			rra(stack_a);
		while (target != *stack_b)
			rb(stack_b);
	}
}

int	is_on_top(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = get_cheap_push(stack_a);
	if (node == *stack_a && node->target == *stack_b)
		return (1);
	if (node == *stack_a)
	{
		align_only_b(stack_a, stack_b);
		return (1);
	}
	if (node->target == *stack_b)
	{
		align_only_a(stack_a);
		return (1);
	}
	return (0);
}

void	get_to_top(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = get_cheap_push(stack_a);
	if (!is_on_top(stack_a, stack_b))
	{
		if (node->push_cost == 0)
			return ;
		if (node->median == 0 && node->target->median == 0)
			align_both_mzero(stack_a, stack_b);
		else if (node->median == 1 && node->target->median == 1)
			align_both_mone(stack_a, stack_b);
		else if (node->median == 0 && node->target->median == 1)
			align_diff_m(stack_a, stack_b);
		else if (node->median == 1 && node->target->median == 0)
			align_diff_m(stack_a, stack_b);
	}
}
