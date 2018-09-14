# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 13:08:28 by rhohls            #+#    #+#              #
#    Updated: 2018/09/14 10:09:36 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar
TEST ?= test.c

# Path
SRC_PATH = ./src/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libft/
FUNC_PATH = ./src_func/

# Files
SRC_FILE =	op.c	\
			print.c	\
			read_file.c	\
			error.c	\
			get_int.c	\
			init_vm.c	\
			vm_cycle.c	\
			cursor.c	\
			death_cycle.c	\
			ex_instructions.c	\
			get_info.c	\

FUNC_FILE = cw_sti.c \

# Manipulate
OBJ_FILE = $(SRC_FILE:%.c=%.o)
FUN_OBJ_FILE = $(FUNC_FILE:%.c=%.o)

SRC = 		$(addprefix $(SRC_PATH), $(FUNC_FILE)) 
OBJ = 		$(addprefix $(OBJ_PATH), $(OBJ_FILE)) 

FUNC_SRC =	$(addprefix $(FUNC_PATH), $(FUN_OBJ_FILE)) 
FUNC_OBJ =	$(addprefix $(OBJ_PATH), $(FUN_OBJ_FILE)) 

COREWAR_MAIN = ./src_vm/main.c

#Compile
CCFLAGS = -Wall -Werror -Wextra
CC = gcc #$(CCFLAGS)

LIBF = $(LIB_PATH)libft.a

#Make Commands
all: $(COREWAR)

$(COREWAR): $(OBJ) $(FUNC_OBJ) $(COREWAR_MAIN)
	@make -C $(LIB_PATH)
	@$(CC) -o $@ $(LIBF) $(OBJ) $(COREWAR_MAIN)
	@echo "\x1b[32m"Finished making $@"\x1b[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I$(INC_PATH) -o $@ -c $<
	@echo Making "\x1b[35m"$@"\x1b[0m"

$(OBJ_PATH)%.o: $(FUNC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I$(INC_PATH) -o $@ -c $<
	@echo Making "\x1b[35m"$@"\x1b[0m"

test: $(OBJ) $(TEST)
	@make -C./libft/
	@$(CC) -o $@ $(OBJ) $(TEST) $(LIBF)
	@./test

clean: 
	@/bin/rm -rf $(OBJ) $(FUNC_OBJ)
	@echo "\x1b[31m"Removed all $(COREWAR) objects"\x1b[0m"

fclean: clean 
	@rm -f $(COREWAR)
	@echo "\x1b[31m"Removed $(COREWAR)"\x1b[0m"
	
cleanall: fclean fcleanlib

cleanlib:
	@make clean -C $(LIB_PATH)

fcleanlib:
	@make fclean -C $(LIB_PATH)

re : fclean all

fre: fcleanall all

.PHONY: re fclean clean all
