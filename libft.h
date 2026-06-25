/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:28:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/06/25 20:35:14 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//! Includes

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

// ! Part 1 - Libc functions

int	ft_isalpha(int ch);
int	ft_isalnum(int ch);
int	ft_isascii(int ch);
int	ft_isprint(int ch);
int	ft_tolower(int ch);
int	ft_toupper(int ch);
int	ft_isdigit(int ch);

// strings functions

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len)

// memory functions 

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

// convertir functions

int	ft_atoi(const char *nptr);


// ! Part 2 - Additional functions

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);


#endif