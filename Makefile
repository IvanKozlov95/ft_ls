# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 16:43:23 by ikozlov           #+#    #+#              #
#    Updated: 2019/03/04 20:34:24 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

# colors
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m

# dirs
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/

# compiler flags
CPP = gcc
ENV = ${C_ENV}
ifeq ($(ENV), DEV)
	CFLAGS = -g
else ifeq ($(ENV), PROD)
	CFLAGS = -Wall -Wextra -Werror
endif

# files
SRC_FILES = main.c ls.c parse.c process.c arg.c dir.c file.c utils.c debug_helper.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libs
LIBFT = ft
LIBS = -L $(LIBFT_DIR) -l $(LIBFT)

# includes
INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR)includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CPP) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(SRC_DIR)*/%.c
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		rm -rf $(OBJ_DIR);\
		echo "$(WARN_COLOR)FT_LS: $(OK_COLOR)[INFO] Object folder removed$(NO_COLOR)";\
	fi;

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if test -e $(NAME); then\
		/bin/rm -rf $(NAME);\
		echo "$(WARN_COLOR)FT_LS: $(OK_COLOR)[INFO] Executable removed$(NO_COLOR)";\
	fi;

re: fclean all

.PHONY: all clean fclean re
