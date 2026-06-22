/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:12:24 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/23 01:41:01 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	i = 0;
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (i < n)
	{
		if (first[i] != second[i])
		{
			if (first[i] > second[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    // Test 1: Equal strings
    printf("ft: %d | real: %d\n", 
	ft_memcmp("Hello", "Hello", 5), memcmp("Hello", "Hello", 5));

    // Test 2: Different strings
    printf("ft: %d | real: %d\n", 
	ft_memcmp("Hello", "Hella", 5), memcmp("Hello", "Hella", 5));

    // Test 3: First byte differs
    printf("ft: %d | real: %d\n", 
	ft_memcmp("Hello", "World", 5), memcmp("Hello", "World", 5));

    // Test 4: n = 0
    printf("ft: %d | real: %d\n", 
	ft_memcmp("Hello", "World", 0), memcmp("Hello", "World", 0));

    // Test 5: Compare with null terminator (memcmp doesn't stop at '\0')
    printf("ft: %d | real: %d\n", 
	ft_memcmp("Hello\0World", "Hello\0Xorld", 11), 
	memcmp("Hello\0World", "Hello\0Xorld", 11));

    // Test 6: Binary data (integers)
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    printf("ft: %d | real: %d\n", 
	ft_memcmp(arr1, arr2, sizeof(arr1)), memcmp(arr1, arr2, sizeof(arr1)));

    return (0);
}*/