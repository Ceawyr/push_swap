/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:02:01 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:03:18 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max(t_list **stack)
{
	t_list	*higher;
	t_list	*node;
	int		max;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	higher = node;
	max = node->data;
	while (node)
	{
		if (max < node->data)
		{
			higher = node;
			max = node->data;
		}
		node = node->next;
	}
	return (higher);
}

t_list	*get_min(t_list **stack)
{
	t_list	*mini;
	t_list	*node;
	int		min;

	if ((*stack) && !(*stack)->next)
	{
		mini = *stack;
		return (mini);
	}
	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	mini = *stack;
	node = *stack;
	min = node->data;
	while (node->next)
	{
		node = node->next;
		if (min > node->data)
		{
			mini = node;
			min = node->data;
		}
	}
	return (mini);
}

static t_list	*find_closer_smaller(t_list *stack_b, int value)
{
	t_list	*node;
	t_list	*closer;

	node = stack_b;
	closer = NULL;
	while (node)
	{
		if (node->data < value && (!closer || node->data > closer->data))
			closer = node;
		node = node->next;
	}
	return (closer);
}

void	get_target_smaller(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*closert_smaller;

	closert_smaller = NULL;
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_a = *stack_a;
	while (current_a)
	{
		closert_smaller = find_closer_smaller(*stack_b, current_a->data);
		if (!closert_smaller)
			closert_smaller = get_max(stack_b);
		current_a->target = closert_smaller;
		current_a = current_a->next;
	}
}
