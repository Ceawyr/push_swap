/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:50:16 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:21:29 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(int code)
{
	if (code == 1)
		exit(EXIT_FAILURE);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
