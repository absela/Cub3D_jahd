# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absela <absela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:53:14 by abelahce          #+#    #+#              #
#    Updated: 2023/04/18 06:02:29 by absela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc

SRC := ft_isalnum.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcat.c \
	   ft_bzero.c \
	   ft_strrchr.c \
	   ft_strchr.c \
	   ft_toupper.c  \
	   ft_tolower.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strncmp.c \
	   ft_strnstr.c\
	   ft_strlcpy.c \
	   ft_isalpha.c \
	   ft_atoi.c 	\
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_putendl_fd.c \
	   ft_putchar_fd.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_itoa.c \
	   ft_split.c \
	   

REMOVE := rm -rf

OBJ := $(SRC:.c=.o)

HDR := libft.h

FLAGS := -Wall -Wextra -Werror

%.o : %.c $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : all

all : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	$(REMOVE) $(OBJ)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all clean fclean re


