# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:23:16 by otodd             #+#    #+#              #
#    Updated: 2024/12/06 14:25:09 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW		=	\033[1;33m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
BLUE		=	\033[1;34m
CYAN		=	\033[1;36m
NC			=	\033[0m

CC			=	c++
CXXFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
NAME		=	zombie

INCLUDE_DIR	=	include
SRC_DIR 	= 	src
OBJ_DIR 	= 	obj

SRC			=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Zombie.cpp \
				$(SRC_DIR)/newZombie.cpp \
				$(SRC_DIR)/randomChump.cpp

OBJS 		= 	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
HEADERS		=	-I$(INCLUDE_DIR)

all: $(NAME)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)CPP01$(NC)]  Creating obj directory..."; \
		mkdir -p obj; \
	fi	

$(NAME): $(OBJS)
	@echo "[$(GREEN)CPP01$(NC)]  Building $@..."
	@$(CC) $(CXXFLAGS) $(HEADERS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | dir
	@mkdir -p $(@D)
	@echo "[$(BLUE)CPP01$(NC)]  Compiling $< --> $@"
	@$(CC) $(CXXFLAGS) $(HEADERS) -c $< -o $@

clean:
	@echo "[$(YELLOW)CPP01$(NC)]  Cleaning object directory..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)CPP01$(NC)]  Cleaning executable directory..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re