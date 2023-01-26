# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 18:59:19 by fsuomins          #+#    #+#              #
#    Updated: 2023/01/26 20:25:59 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OS	 = $(shell uname)

INCLUDES = ../includes
SRC 	 = ./src

SRCS =  hooks.c \
		julia.c \
		main.c \
		mandelbrot.c \
		utils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))
CC	 = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./miniLibX/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS) 

$(OBJS) : $(SRCS) fractol.h
	cc $(CFLAGS) -c $(SRCS) -I $(INCLUDE) 

all : $(NAME)

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
.PHONY: all clean fclean re