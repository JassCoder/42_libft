/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:28:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/21 20:39:16 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//! Includes

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

// ! Characters formats

int	ft_isalpha(int ch);
int	ft_isalnum(int ch);
int	ft_isascii(int ch);
int	ft_isprint(int ch);
int	ft_tolower(int ch);
int	ft_toupper(int ch);
int	ft_isdigit(int ch);

// ! strings formats

size_t	ft_strlen(char *str);

// ! memory formats

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);


#endif