/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:39:32 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/07 22:24:04 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!dest && !src)
		return (dest);
	i = 0;
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
