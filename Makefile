# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 03:24:15 by ldias-fe          #+#    #+#              #
#    Updated: 2023/02/01 15:00:19 by fsuomins         ###   ########.fr        #
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
			utils.c 

BONUS = $(FILES) tricorn_bonus.c
			
PATH_SRC 		= ./mandatory/src/
SRCS 			= $(addprefix $(PATH_SRC), $(FILES))
OBJS 			= $(FILES:.c=.o)
INCLUDES 		= -I ./mandatory/includes -I ./libft
PATH_SRC_BONUS 	= ./bonus/src/
SRCS_BONUS 		= $(addprefix $(PATH_SRC), $(FILES))
OBJS_BONUS 		= $(FILES:.c=.o)
INCLUDES_BONUS 	= -I ./mandatory/includes -I ./libft

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft

%.o: $(PATH_SRC)%.c
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