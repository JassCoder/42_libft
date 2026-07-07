/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:07:13 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/07 20:52:50 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*src;
	unsigned char	check;
	int				last;
	int				i;

	src = (unsigned char *)s;
	check = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		i++;
	}
	last = i;
	while (last >= 0)
	{
		if (src[last] == check)
			return ((char *)(src + last));
		last--;
	}
	return (NULL);
}
