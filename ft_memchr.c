/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:36:16 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/21 20:54:51 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	check;
	size_t			i;

	temp = (unsigned char *)s;
	check = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (temp[i] == check)
		{
			return ((void *)&temp[i]);
		}
		i++;
	}
	return (NULL);
}
