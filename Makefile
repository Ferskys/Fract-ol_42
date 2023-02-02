# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 03:24:15 by ldias-fe          #+#    #+#              #
#    Updated: 2023/02/02 13:40:05 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus
FLAGS 			= -Wall -Wextra -Werror -g3
LIBFTFLAGS 		= -L ./libft/ -lft
LIBXFLAGS 		= -lmlx -lXext -lX11 -lm -lz

FILES 	= 	hooks.c \
			julia.c \
			main.c \
			mandelbrot.c \
			utils.c 

FILES_BONUS :=	hooks_bonus.c \
				julia_bonus.c \
				main_bonus.c \
				mandelbrot_bonus.c \
				utils_bonus.c \
				tricorn_bonus.c
			
FILES_BONUS := $(addprefix bonus/src_bonus/, $(FILES_BONUS))
			
PATH_SRC 		= ./mandatory/src/
SRCS 			= $(addprefix $(PATH_SRC), $(FILES))
OBJS 			= $(FILES:.c=.o)
INCLUDES 		= -I ./mandatory/includes -I ./libft

PATH_SRC_BONUS 	= ./bonus/src_bonus/
SRCS_BONUS 		= $(addprefix $(PATH_SRC_BONUS), $(FILES_BONUS))
OBJS_BONUS 		= $(FILES_BONUS:.c=.o)
INCLUDES_BONUS 	= -I ./bonus/includes_bonus -I ./libft

all:	$(NAME)

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft --no-print-directory

%.o: $(PATH_SRC)%.c
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@

bonus:  $(BONUS)

$(BONUS): libft/libft.a $(OBJS_BONUS)
	cc $(INCLUDES_BONUS) $(FLAGS) -o $@ $(OBJS_BONUS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES_BONUS)
	
%.o: $(PATH_SRC_BONUS)%.c
	@cc $(FLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
		rm -rf $(OBJS) $(OBJS_BONUS)
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME) $(BONUS)
		make -C ./libft fclean

re:		fclean all

.PHONY: all bonus clean fclean re

# -0.4  0.6
# 0.285 0.01
# -0.8 0.156