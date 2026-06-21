/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:30:58 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/21 20:02:50 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	fill;
	size_t			i;

	temp = (unsigned char *)s;
	fill = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		temp[i] = fill;
		i++;
	}
	return (s);
}
