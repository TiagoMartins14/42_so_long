# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 07:44:06 by tiaferna          #+#    #+#              #
#    Updated: 2023/11/30 09:18:51 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RESET	= \033[0m
BOLD	= \033[1m
FAINT	= \033[2m
ITALIC	= \033[3m
ULINE	= \033[4m
SBLINK	= \033[5m
FBLINK	= \033[6m
REVCOL	= \033[7m
HIDDEN	= \033[8m
CROSS	= \033[9m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LFLAGS = -L$(LIBFT_DIR) -lft -L$(LMLX_DIR) -lmlx

RM = rm -rf

SRCDIR = src/mandatory

LIBFT_DIR =  src/libft

LMLX_DIR = minilibx-linux

SRCS = 	src/mandatory/so_long.c src/mandatory/events.c src/mandatory/map_checkers.c \
		src/mandatory/image_setters.c src/mandatory/free_structs.c src/mandatory/ft_strndup_inv.c \
		src/mandatory/map_creators.c src/mandatory/draw_map.c src/mandatory/moves.c \
		src/mandatory/init.c

OBJS = $(SRCS:.c=.o)

ifeq ($(FOUND_OS), Darwin)
				CC = gcc
				LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(FOUND_OS), FreeBSD)
				CC = clang
else
				CC = cc
				LFLAGS += -lbsd -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LMLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	clear
	@echo "$(GREEN)./so_long executable is ready!$(RESET)"

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	cd minilibx-linux && make clean
	$(RM) $(OBJS)
	clear
	@echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	$(MAKE) -s -C $(LIBFT_DIR) fclean
	cd minilibx-linux && make clean
	$(RM) $(NAME)
	clear
	@echo "$(RED)Object files and executable have been deleted!$(RESET)"

re: fclean all

download:
	@ wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@ tar -xzf minilibx-linux.tgz
	@ rm minilibx-linux.tgz

.PHONY: all clean fclean re