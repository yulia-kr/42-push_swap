# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 10:28:58 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/10/02 11:07:26 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	=	checker

SRC 	=	check_num.c push_swap.c lists.c create_stacks.c print_stacks.c\
			push.c swap.c rotate.c reverse.c mediana.c sort_small.c sort_small2.c\
			sort_big.c

SRC_B	=	cheker.c check_num.c lists.c create_stacks.c print_stacks.c\
			push.c swap.c rotate.c reverse.c mediana.c sort_small.c sort_small2.c\
			sort_big.c 

OBJ		=	$(SRC:%.c=%.o)

OBJ_B	=	$(SRC_B:%.c=%.o)

LIBFT	=	libft/libft.a

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------


.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIBFT) -o $(NAME_B)
			
libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all
