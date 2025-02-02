/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:52:54 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:20:34 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*current;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (1);
	current = *stack_a;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*init_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!is_sorted(stack_a) && ft_lstsize(*stack_a) > 3)
	{
		pb(stack_a, &stack_b);
		pb(stack_a, &stack_b);
	}
	return (stack_b);
}

void	ft_start(t_list **stack_a)
{
	size_t	i;
	t_list	*stack_b;

	if (is_sorted(stack_a))
		return ;
	i = ft_lstsize(*stack_a);
	if (i <= 3)
	{
		small_ps(stack_a);
		return ;
	}
	stack_b = init_b(stack_a);
	sort(stack_a, &stack_b);
}
