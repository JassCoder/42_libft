/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:27:25 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/23 01:10:43 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*o1;
	unsigned char	*o2;
	size_t			i;

	i = 0;
	o1 = (unsigned char *)s1;
	o2 = (unsigned char *)s2;
	while (i < n && o1[i] && o2[i] && (o1[i] == o2[i]))
		i++;
	if (i == n)
		return (0);
	return (o1[i] - o2[i]);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    // Test 1: Equal strings
    printf("ft: %d | real: %d\n", 
	ft_strncmp("Hello", "Hello", 5), strncmp("Hello", "Hello", 5));

    // Test 2: Different strings
    printf("ft: %d | real: %d\n", 
	ft_strncmp("Hello", "Hella", 5), strncmp("Hello", "Hella", 5));

    // Test 3: First char differs
    printf("ft: %d | real: %d\n", 
	ft_strncmp("Hello", "World", 5), strncmp("Hello", "World", 5));

    // Test 4: Limit n stops early
    printf("ft: %d | real: %d\n", 
	ft_strncmp("Hello", "Hella", 3), strncmp("Hello", "Hella", 3));

    // Test 5: n = 0
    printf("ft: %d | real: %d\n", 
	ft_strncmp("Hello", "World", 0), strncmp("Hello", "World", 0));

    return (0);
}*/