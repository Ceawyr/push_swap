/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:43:08 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/20 19:49:34 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j] == '0' || (str[j] == '+' || str[j] == '-'))
		j++;
	while (str[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}
