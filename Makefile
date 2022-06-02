# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:50:21 by atron             #+#    #+#              #
#    Updated: 2022/06/01 14:09:20 by cbignon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef config
  config=release
endif

ifndef architecture
  architecture=x64
endif

ifndef platform
  platform=linux
endif

SILENT = @

NAME = minishell

CC = clang

INCLUDE = -I./libft/
INCLUDE += -I./include
INCLUDE += -I.

LIB_PATH = -L./libft/

LIBS = -lft
LIBS += -lreadline

FLAGS = -Wall -Wextra -Werror# -std=gnu99

ifeq ($(architecture), x64)
  FLAGS += -DX64
endif

ifeq ($(platform), linux)
  FLAGS += -DUNIX
  FLAGS += -DLINUX
endif

ifeq ($(platform), mac)
  FLAGS += -DUNIX
  FLAGS += -DMACOS
endif

ifeq ($(config), debug)
  FLAGS += -g3
  FLAGS += -DDEBUG
  FLAGS += -fstack-protector
endif

ifeq ($(config), memory)
  FLAGS += -fsanitize=address
  FLAGS += -DDEBUG
  FLAGS += -g3
  FLAGS += -fstack-protector
endif

ifeq ($(config), leaks)
  FLAGS += -fsanitize=leak
  FLAGS += -DDEBUG
  FLAGS += -g3
endif

OBJDIR = ./intermediate/$(config)/

TMPOBJS = $(SRCS:.c=.o)
TMPMAINOBJ = $(MAIN:.c=.o)

OBJS = $(addprefix $(OBJDIR), $(TMPOBJS))
MAINOBJ = $(addprefix $(OBJDIR), $(TMPMAINOBJ))

OBJDIRECTORIES = $(OBJDIR)
OBJDIRECTORIES += $(OBJDIR)core
OBJDIRECTORIES += $(OBJDIR)env
OBJDIRECTORIES += $(OBJDIR)ft_split_args
OBJDIRECTORIES += $(OBJDIR)utils
OBJDIRECTORIES += $(OBJDIR)tests
OBJDIRECTORIES += $(OBJDIR)utils
OBJDIRECTORIES += $(OBJDIR)processes
OBJDIRECTORIES += $(OBJDIR)garbage_collection

SRCS =

#MAIN
#############################################################
#############################################################
MAIN = main.c

#CORE
#############################################################
#############################################################
SRCS += core/exec_cmd.c
SRCS += core/exec_utils.c
SRCS += core/ft_get_bin_path.c
SRCS += core/path.c
SRCS += core/prompt.c
SRCS += core/pipe.c
SRCS += core/close_fd.c
SRCS += core/signal_handling.c
SRCS += core/clean_quotes.c
SRCS += core/redirect.c
SRCS += core/heredoc.c

#PROCESSES
#############################################################
#############################################################
SRCS += processes/setup_processes.c
SRCS += processes/run_wait_processes.c
SRCS += processes/get_processes.c
SRCS += processes/clean_processes.c
SRCS += processes/processes_utils.c
SRCS += processes/redirect.c

#FT_SPLIT_ARGS
#############################################################
#############################################################
SRCS += ft_split_args/ft_split_args.c
SRCS += ft_split_args/arg_length.c
SRCS += ft_split_args/args_count.c
SRCS += ft_split_args/args_info.c
SRCS += ft_split_args/args_memory.c

#ENV
#############################################################
#############################################################
SRCS += env/env_utils.c
SRCS += env/env.c
SRCS += env/environ.c
SRCS += env/export.c
SRCS += env/unset.c
SRCS += env/var_utils.c
SRCS += env/expand_utils.c
SRCS += env/parse_cmd_dollar.c
SRCS += env/heredoc_expansion.c
SRCS += env/cd.c
SRCS += env/echo.c
SRCS += env/pwd.c
SRCS += env/ft_split_space_protect.c
SRCS += env/split_protect_utils.c
SRCS += env/expand_parser.c
SRCS += env/dollar_utils.c
SRCS += env/exit.c

#UTILS
#############################################################
#############################################################
SRCS += utils/ft_str_equ.c
SRCS += utils/ft_tabcpy.c
SRCS += utils/ft_find_in_tab.c
SRCS += utils/ft_read_dir.c
SRCS += utils/ft_sort_tab.c
SRCS += utils/ft_printerr.c
SRCS += utils/ft_syntax_check.c
SRCS += utils/ft_tab_to_str.c
SRCS += utils/first_space_or_quote.c
SRCS += utils/get_closing_quote.c
SRCS += utils/append_index.c
SRCS += utils/malloc_verify.c
SRCS += utils/ft_skip_quotes.c

#RULES
#############################################################
#############################################################

$(NAME): prep ${OBJS} $(MAINOBJ)
	${MAKE} -C libft/ -f Makefile config=$(config) platform=${platform} architecture=${architecture}
	$(CC) $(FLAGS) -o $(NAME) $(MAINOBJ) $(OBJS) $(LIB_PATH) $(LIBS)

all: compile

compile:
	$(MAKE) prep
	$(MAKE) $(NAME)

clean:
	rm -rf intermediate
	rm -f prep
	${MAKE} -C libft/ -f Makefile clean

fclean:
	rm -rf intermediate
	rm -f prep
	rm -f $(NAME)
	${MAKE} -C libft/ -f Makefile fclean

re:		fclean all

-include valgrind.mk

# valgrind:
# 	${MAKE} -C . -f Makefile config=debug platform=${platform} architecture=${architecture} logging=${logging}
# 	valgrind -s --leak-check=full --show-leak-kinds=all --suppressions=ignoreliberror ./$(NAME)

valgrind-re:
	${MAKE} -C . -f Makefile re config=debug platform=${platform} architecture=${architecture} logging=${logging}
	valgrind -s --leak-check=full --show-leak-kinds=all --suppressions=ignoreliberror /$(NAME)

libft:
	${MAKE} -C libft/ -f Makefile config=$(config) platform=${platform} architecture=${architecture}

prep:
	$(SILENT)mkdir -p ${OBJDIRECTORIES}
	touch prep

$(OBJDIR)%.o: %.c
	@echo $(notdir $<)
	$(CC) $(FLAGS) $(INCLUDE) -c $<  -o $(OBJDIR)$(<:.c=.o)

.PHONY: ${NAME} all compile prep clean fclean re valgrind libft bonus