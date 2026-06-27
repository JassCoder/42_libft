# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsingh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/27 21:33:14 by jsingh            #+#    #+#              #
#    Updated: 2026/06/27 21:33:29 by jsingh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsingh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 16:28:41 by jsingh            #+#    #+#              #
#    Updated: 2026/06/27 18:19:27 by jsingh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================== VARIABLES ===========================

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# =========================== SOURCE FILES ===========================

# Part 1 - Libc Functions
SRCS_P1		= ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_tolower.c \
			  ft_toupper.c

# Part 2 - Additional Functions
SRCS_P2		= ft_itoa.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putstr_fd.c \
			  ft_split.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strmapi.c \
			  ft_strtrim.c \
			  ft_substr.c

# Part 3 - Bonus (Linked List)
SRCS_BONUS	= ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c

# All source files
SRCS		= $(SRCS_P1) $(SRCS_P2)
SRCS_ALL	= $(SRCS) $(SRCS_BONUS)

# Object files
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
OBJS_ALL	= $(SRCS_ALL:.c=.o)

# =========================== RULES ===========================

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_ALL)
	$(AR) $(NAME) $(OBJS_ALL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus