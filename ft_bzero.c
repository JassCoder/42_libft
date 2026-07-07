/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:05:32 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/07 22:24:33 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*container;
	size_t			i;

	container = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		container[i] = 0;
		i++;
	}
}
