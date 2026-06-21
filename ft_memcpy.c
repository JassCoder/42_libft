/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:22:08 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/21 22:51:39 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*taker;
	unsigned char	*giver;
	size_t			i;

	taker = (unsigned char *)dest;
	giver = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		taker[i] = giver[i];
		i++;
	}
	return (dest);
}
