/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:16:17 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/01 02:07:29 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_top_pos(t_list *stack, t_list *target)
{
	t_rotation	count;

	count = (t_rotation){0, 0, 0, 0, 0, 0, 0};
	while (stack->previous != NULL && target->previous != NULL)
	{
		count.rr++;
		stack = stack->previous;
		target = target->previous;
	}
	while (stack->previous != NULL)
	{
		count.ra++;
		stack = stack->previous;
	}
	while (target->previous != NULL)
	{
		count.rb++;
		target = target->previous;
	}
	count.total = count.rr + count.ra + count.rb;
	return (count.total);
}

int	median_bot_pos(t_list *stack, t_list *target_stack)
{
	t_rotation	count;

	count = (t_rotation){0, 0, 0, 0, 0, 0, 0};
	while (stack->next != NULL && target_stack->next != NULL)
	{
		count.rrr++;
		stack = stack->next;
		target_stack = target_stack->next;
	}
	while (stack->next != NULL)
	{
		count.rra++;
		stack = stack->next;
	}
	while (target_stack->next != NULL)
	{
		count.rrb++;
		target_stack = target_stack->next;
	}
	if (!stack->next && !target_stack->next)
		count.total = count.rrr + count.rra + count.rrb;
	return (count.total + 2);
}

int	median_diff_pos(t_list *node, t_list *target_node, int value)
{
	t_rotation	count;

	count = (t_rotation){0, 0, 0, 0, 0, 0, 0};
	while (node->previous != NULL && value == 0)
	{
		count.ra++;
		node = node->previous;
	}
	while (target_node->next != NULL && value == 0)
	{
		count.rrb++;
		target_node = target_node->next;
	}
	while (node->next != NULL && value == 1)
	{
		count.rra++;
		node = node->next;
	}
	while (target_node->previous != NULL && value == 1)
	{
		count.rb++;
		target_node = target_node->previous;
	}
	count.total = count.ra + count.rrb + count.rb + count.rra;
	return (count.total + 1);
}

void	fil_rotation_data(t_list **stack_a)
{
	t_list		*node;
	t_rotation	cost;

	node = *stack_a;
	while (node)
	{
		cost = (t_rotation){0, 0, 0, 0, 0, 0, 0};
		if (node->median == 0 && node->target && node->target->median == 0)
			cost.total = median_top_pos(node, node->target);
		else if (node->median == 1 && node->target && node->target->median == 1)
			cost.total = median_bot_pos(node, node->target);
		else if (node->median == 0 && node->target && node->target->median == 1)
			cost.total = median_diff_pos(node, node->target, 0);
		else if (node->median == 1 && node->target &&node->target->median == 0)
			cost.total = median_diff_pos(node, node->target, 1);
		node->push_cost = cost.total;
		node = node->next;
	}
}

void	get_push_cost(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	set_median(stack_a);
	set_median(stack_b);
	fil_rotation_data(stack_a);
}
