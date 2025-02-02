/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:04:57 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 22:54:07 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_median(t_list **stack, size_t len)
{
	t_list	*median;
	size_t	middle;
	size_t	i;

	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	middle = len / 2;
	median = *stack;
	i = 0;
	while (i < middle && median->next)
	{
		median = median->next;
		i++;
	}
	return (median);
}

void	set_median(t_list **stack)
{
	t_list	*node;
	t_list	*median_node;
	size_t	lst_size;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst_size = ft_lstsize(*stack);
	median_node = get_median(stack, lst_size);
	node = *stack;
	while (node)
	{
		node->median = 0;
		node = node->next;
	}
	node = *stack;
	while (node && node != median_node)
		node = node->next;
	while (node)
	{
		node->median = 1;
		node = node->next;
	}
}

static t_list	*find_closer_bigger(t_list *stack_a, int value)
{
	t_list	*node;
	t_list	*closer;

	node = stack_a;
	closer = NULL;
	while (node)
	{
		if (node->data > value && (!closer || node->data < closer->data))
			closer = node;
		node = node->next;
	}
	return (closer);
}

void	get_target_bigger(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*closert_bigger;

	closert_bigger = NULL;
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_b = *stack_b;
	while (current_b)
	{
		closert_bigger = find_closer_bigger(*stack_a, current_b->data);
		if (!closert_bigger)
			closert_bigger = get_min(stack_a);
		current_b->target = closert_bigger;
		current_b = current_b->next;
	}
}
