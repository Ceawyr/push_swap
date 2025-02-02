/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:22:01 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 22:56:56 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

static int	scan_input(char **argv)
{
	int	i;
	int	j;
	int	current;

	i = 1;
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

	i = 1;
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

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (argc < 2)
		ft_exit_error(1);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			ft_exit_error(0);
		argv = ft_split(argv[1], ' ');
		if (!argv)
			ft_exit_error(0);
		a = init_a_bis(argv);
		free_tab(argv);
	}
	else if (!scan_input(argv))
		a = init_a(argv);
	else
		ft_exit_error(0);
	ft_start(&a);
	free_list(&a);
	return (0);
}
