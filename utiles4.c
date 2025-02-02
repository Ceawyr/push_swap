/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:30:43 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 20:54:16 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fil_rotation_data_bis(t_list **stack_b)
{
	t_list		*node;
	t_list		*target;
	t_rotation	cost;

	node = *stack_b;
	target = node->target;
	while (node)
	{
		cost = (t_rotation){0, 0, 0, 0, 0, 0, 0};
		if (node->median == 0 && target->median == 0)
			cost.total = median_top_pos(node, target);
		else if (node->median == 1 && target->median == 1)
			cost.total = median_bot_pos(node, target);
		else if (node->median == 0 && target->median == 1)
			cost.total = median_diff_pos(node, target, 0);
		else if (node->median == 1 && target->median == 0)
			cost.total = median_diff_pos(node, target, 1);
		node->push_cost = cost.total;
		node = node->next;
	}
}

void	get_push_cost_bis(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	set_median(stack_b);
	set_median(stack_a);
	fil_rotation_data_bis(stack_b);
}