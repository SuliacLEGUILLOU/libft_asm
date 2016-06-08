# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 11:53:15 by sle-guil          #+#    #+#              #
#    Updated: 2015/06/11 18:00:03 by sle-guil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
LOGIN_AUTEUR = sle-guil

HEADER = ./
SRCS =	ft_bzero.s		ft_isdigit.s	ft_isalpha.s	ft_isalnum.s	ft_cat.s	\
		ft_isascii.s	ft_isprint.s	ft_memcpy.s		ft_memset.s		ft_puts.s	\
		ft_strcat.s		ft_strcmp.s		ft_strcpy.s		ft_strdup.s		ft_strlen.s	\
		ft_tolower.s	ft_toupper.s	ft_isspace.s	ft_putstr.s		ft_putstr_fd.s

OBJS = $(SRCS:.s=.o)

CASM = /nfs/zfs-student-3/users/2014_paris/sle-guil/.brew/bin/nasm
CFLAG = -f macho64

#===============================#
#		Compilation rules 		#
#===============================#

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "LibftASM is created and indexed."

%.o: %.s
	@$(CASM) $(CFLAG) $< -o $@

test: $(NAME)
	@clang $(NAME) libfts.h main.c

#===============================#
#		repository rules		#
#===============================#

auteur:
	@echo "$(LOGIN_AUTEUR)" > auteur

#===============================#
#		Cleaning rules			#
#===============================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "*** Object file cleaned ***"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "*** $(NAME) cleaned ***"

re: fclean all

.PHONY: all clean fclean re auteur test
