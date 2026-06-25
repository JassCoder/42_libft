/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:36:22 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/25 20:32:12 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size < dst_len)
		return (size + src_len);
	i = 0;
	while (i < (size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>  // For Linux

#include "libft.h"
#include <stdio.h>

int main(void)
{
    char dst[20] = "Hello";
    size_t len;

    // Test 1: Normal concatenation
    len = ft_strlcat(dst, " World", 20);
    printf("dst: '%s' | len: %zu\n", dst, len);

    // Test 2: Truncation
    char dst2[10] = "Hello";
    len = ft_strlcat(dst2, " World", 10);
    printf("dst: '%s' | len: %zu\n", dst2, len);

    // Test 3: size <= dst_len (no space)
    char dst3[10] = "Hello";
    len = ft_strlcat(dst3, " World", 5);
    printf("dst: '%s' | len: %zu\n", dst3, len);

    // Test 4: Empty src
    char dst4[20] = "Hello";
    len = ft_strlcat(dst4, "", 20);
    printf("dst: '%s' | len: %zu\n", dst4, len);

    return (0);
}