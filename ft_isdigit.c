/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:54:34 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/20 16:47:09 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
        char a[] = {'1', 'a', '@', '2', 'm'};
        int len = strlen(a) - 1;

        for (int i = 0; i <= len; i++)
        {
                if (ft_isdigit(a[i]))
		{
			printf("%c is numeric,     returning %d",a[i],ft_isdigit(a[i]));
		}
		else
			printf("%c is not numeric, returning %d",a[i],ft_isdigit(a[i]));
		printf("\n");
        }
	return 0;
}
*/