/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:04:54 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/19 15:53:04 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
        char a[] = {'a', 1, '@', 2, 'm'};
        int len = strlen(a) - 1;

        for (int i = 0; i <= len; i++)
        {
                if (ft_isalpha(a[i]))
		{
			printf("%c is alphabet, returning %d",a[i],ft_isalpha(a[i]));
		}
		else
			printf("%c is not alphabet, returning %d",a[i],ft_isalpha(a[i]));
		printf("\n");
        }
	return 0;
}*/
