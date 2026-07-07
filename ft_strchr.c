/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 18:49:50 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/30 04:56:07 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	check;
	unsigned char	*src;
	int				i;

	i = 0;
	src = (unsigned char *)s;
	check = (unsigned char)c;
	while (src[i] != '\0')
	{
		if (src[i] == check)
		{
			return ((char *)src + i);
		}
		i++;
	}
	if (check == '\0')
		return ((char *)src + i);	
	return (NULL);
}

