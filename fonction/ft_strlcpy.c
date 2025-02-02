/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:40:28 by cnamoune          #+#    #+#             */
/*   Updated: 2025/01/13 22:44:10 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (y < size - 1 && src[y] != '\0')
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (i);
}
