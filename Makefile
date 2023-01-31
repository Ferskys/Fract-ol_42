# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 03:24:15 by ldias-fe          #+#    #+#              #
#    Updated: 2023/01/31 18:28:29 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS 			= -Wall -Wextra -Werror -g3
LIBFTFLAGS 		= -L ./libft/ -lft
LIBXFLAGS 		= -lmlx -lXext -lX11 -lm -lz

FILES 	= 	hooks.c \
			julia.c \
			main.c \
			mandelbrot.c \
			utils.c \
			tricorn.c 
			
SRCS = $(addprefix ./src/, $(FILES))
OBJS 		= $(SRCS:.c=.o)
INCLUDES = -I ./includes -I ./libft

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft

%.o: %.c
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@
	
all:	$(NAME)

clean:
		rm -rf $(OBJS) 
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean

re:		fclean all clean

.PHONY: all clean fclean re