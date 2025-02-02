/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:08:37 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:16:48 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotate(t_list **stack_a)
{

	t_list	*smallest;	
	smallest = get_min(stack_a);
	if (smallest == NULL)
		return ;
	set_median(stack_a);
	while (*stack_a != smallest)
	{
		if (smallest->median == 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	small_ps(t_list **node)
{
	int	size;

	size = ft_lstsize(*node);
	if (size == 2)
	{
		if ((*node)->data > (*node)->next->data)
			sa(node);
		return ;
	}
	if (ft_lstsize(*node) == 3 && ((*node)->data > (*node)->next->data)
		&& (*node)->data > (*node)->next->next->data)
		ra(node);
	if ((*node)->data < (*node)->next->data
		&& ((*node)->next->data > (*node)->next->next->data))
		rra(node);
	if ((*node)->data > (*node)->next->data)
		sa(node);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	get_to_top(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !*stack_b || !*stack_a)
		return ;
	get_to_top_bis(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
	{
		get_target_smaller(stack_a, stack_b);
		get_push_cost(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
	}
	small_ps(stack_a);
	while (*stack_b)
	{
		get_target_bigger(stack_a, stack_b);
		get_push_cost_bis(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
	final_rotate(stack_a);
}
