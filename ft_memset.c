/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:51:02 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/07 20:53:08 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*container;
	unsigned char	filler;
	size_t			i;

	container = (unsigned char *)s;
	filler = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		container[i] = filler;
		i++;
	}
	return (s);
}
