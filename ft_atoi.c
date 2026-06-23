/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 02:03:02 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/23 21:57:37 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr [i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	if (s == 1)
		return (r);
	return (r * -1);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("ft: %d | real: %d\n", ft_atoi("42"), atoi("42"));
    printf("ft: %d | real: %d\n", ft_atoi("-42"), atoi("-42"));
    printf("ft: %d | real: %d\n", ft_atoi("   -42"), atoi("   -42"));
    printf("ft: %d | real: %d\n", ft_atoi("42abc"), atoi("42abc"));
    printf("ft: %d | real: %d\n", ft_atoi("abc42"), atoi("abc42"));
    printf("ft: %d | real: %d\n", ft_atoi(""), atoi(""));
    printf("ft: %d | real: %d\n", ft_atoi("   "), atoi("   "));
    printf("ft: %d | real: %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
    printf("ft: %d | real: %d\n", ft_atoi("2147483647"), atoi("2147483647"));
    return (0);
}
*/