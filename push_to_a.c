/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:09:45 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:17:23 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_on_top_bis(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_b);
	target = node->target;
	if (node == *stack_b && target == *stack_a)
		return (1);
	if (node == *stack_b)
	{
		align_only_a_bis(stack_a, stack_b);
		return (1);
	}
	if (target == *stack_a)
	{
		align_only_b_bis(stack_b);
		return (1);
	}
	return (0);
}

void	align_both_mzero_bis(t_list	**stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_b);
	target = node->target;
	while (node != *stack_b && target != *stack_a)
		rr(stack_a, stack_b);
	while (node != *stack_b)
		rb(stack_b);
	while (target != *stack_a)
		ra(stack_a);
}

void	align_both_mone_bis(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_b);
	target = node->target;
	while (node != *stack_b && target != *stack_a)
		rrr(stack_a, stack_b);
	while (node != *stack_b)
		rrb(stack_b);
	while (target != *stack_a)
		rra(stack_a);
}

void	align_diff_m_bis(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_b);
	target = node->target;
	if (node->median == 0 && target->median == 1)
	{
		while (node != *stack_b)
			rb(stack_b);
		while (target != *stack_a)
			rra(stack_a);
	}
	else
	{
		while (node != *stack_b)
			rrb(stack_b);
		while (target != *stack_a)
			ra(stack_a);
	}
}

void	get_to_top_bis(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*target;

	node = get_cheap_push(stack_b);
	target = node->target;
	if (!is_on_top_bis(stack_a, stack_b))
	{
		if (node->push_cost == 0)
			return ;
		if (node->median == 0 && target->median == 0)
			align_both_mzero_bis(stack_a, stack_b);
		else if (node->median == 1 && target->median == 1)
			align_both_mone_bis(stack_a, stack_b);
		else if (node->median == 0 && target->median == 1)
			align_diff_m_bis(stack_a, stack_b);
		else if (node->median == 1 && target->median == 0)
			align_diff_m_bis(stack_a, stack_b);
	}
}
