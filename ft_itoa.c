/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:54:15 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/07 20:53:43 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;
	int		i;

	nb = n;
	len = count_digits(nb);
	str = malloc (len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	i = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

/*#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s;

    s = ft_itoa(42);
    printf("%s\n", s);
    free(s);

    s = ft_itoa(-42);
    printf("%s\n", s);
    free(s);

    s = ft_itoa(0);
    printf("%s\n", s);
    free(s);

    s = ft_itoa(2147483647);
    printf("%s\n", s);
    free(s);

    s = ft_itoa(-2147483648);
    printf("%s\n", s);
    free(s);

    return (0);
}*/