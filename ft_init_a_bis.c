/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:09:28 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/15 23:47:08 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	scan_input(char **argv)
{
	int	i;
	int	j;
	int	current;

	i = 0;
	while (argv[i] != NULL)
	{
		if (!is_numeric(argv[i]))
		{
			if (ft_strlen(argv[i]) > 10)
				ft_exit_error(0);
			current = ft_atoi(argv[i]);
			j = 1;
			while (j < i)
			{
				if (current == ft_atoi(argv[j]))
					ft_exit_error(0);
				j++;
			}
			i++;
		}
		else
			ft_exit_error(0);
	}
	return (0);
}

static t_list	*init_a(char **argv)
{
	t_list	*a;
	t_list	*new_node;
	int		i;

	i = 0;
	a = NULL;
	new_node = NULL;
	while (argv[i] != NULL)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
		{
			free_list(&a);
			ft_exit_error(0);
		}
		if (ft_lstadd_back(&a, new_node))
		{
			free_list(&a);
			ft_exit_error(0);
		}
		i++;
	}
	return (a);
}

t_list	*init_a_bis(char **argv)
{
	t_list	*a;

	a = NULL;
	if (!scan_input(argv))
		a = init_a(argv);
	else
		ft_exit_error(0);
	return (a);
}
