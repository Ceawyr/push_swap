/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:13:13 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/03 19:00:58 by cnamoune         ###   ########.fr       */
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

void	align_only_a_bis(t_list **stack_a, t_list **stack_b)
{
	t_list	*nod;
	t_list	*node;

	nod = get_cheap_push(stack_b);
	if (!nod)
		return ;
	node = nod->target;
	if (node->median == 0)
	{
		while (node != *stack_a)
			ra(stack_a);
	}
	else
	{
		while (node != *stack_a)
			rra(stack_a);
	}
}

void	align_only_b_bis(t_list **stack_b)
{
	t_list	*node;

	node = get_cheap_push(stack_b);
	if (!node)
		return ;
	if (node->median == 0)
	{
		while (node != *stack_b)
			rb(stack_b);
	}
	else
	{
		while (node != *stack_b)
			rrb(stack_b);
	}
}

void	align_only_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*nod;
	t_list	*node;

	nod = get_cheap_push(stack_a);
	if (!nod)
		return ;
	node = nod->target;
	if (node->median == 0)
	{
		while (node != *stack_b)
			rb(stack_b);
	}
	else
	{
		while (node != *stack_b)
			rrb(stack_b);
	}
}

void	align_only_a(t_list **stack_a)
{
	t_list	*node;

	node = get_cheap_push(stack_a);
	if (!node)
		return ;
	if (node->median == 0)
	{
		while (node != *stack_a)
			ra(stack_a);
	}
	else
	{
		while (node != *stack_a)
			rra(stack_a);
	}
}
