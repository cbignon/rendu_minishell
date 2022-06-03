# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atron <atron@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 15:19:24 by atron             #+#    #+#              #
#    Updated: 2021/05/20 15:04:11 by atron            ###   ########.fr        #
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

NAME = libft

CC = clang

INCLUDE = -I./

FLAGS = -Wall -Wextra -Werror -std=c99

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
  FLAGS += -fstack-protector
endif

OBJDIR = ./intermediate/$(config)/

TMPOBJS = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJDIR), $(TMPOBJS))

SRCS =
SRCS += ft_atoi.c
SRCS += ft_atof.c
SRCS += ft_atoll.c
SRCS += ft_atoull.c
SRCS += ft_atoui.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_realloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_lstfind.c
SRCS += ft_lstadd_back.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstclear.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstlast.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstsize.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putnbr_base_fd.c
SRCS += ft_putunbr_base_fd.c
SRCS += ft_putulnbr_base_fd.c
SRCS += ft_putullnbr_base_fd.c
SRCS += ft_putunbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_strndup.c
SRCS += ft_strjoin.c
SRCS += ft_strnjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strnlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_stristr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_memory.c
SRCS += get_next_line.c
SRCS += ft_strclen.c
SRCS += ft_tablen.c
SRCS += ft_tabfree.c
SRCS += ft_chara_count.c
SRCS += get_empty_str.c
SRCS += ft_exit.c

SRCS += garbage_collection/gc_use.c
SRCS += garbage_collection/move_to_gc.c

OBJDIRECTORIES = $(OBJDIR)
OBJDIRECTORIES = $(OBJDIR)garbage_collection

all: compile

$(NAME):	${OBJS}
	$(SILENT) ar -rcs $(NAME).a $^

compile:
	$(SILENT) $(MAKE) prep
	$(SILENT) $(MAKE) $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf intermediate

fclean:
	rm -f $(OBJS)
	rm -rf intermediate
	rm -f $(NAME)

re:	fclean compile

bonus:	compile

prep:
	$(SILENT)mkdir -p $(OBJDIRECTORIES)

$(OBJDIR)%.o: %.c
	@echo $(notdir $<)
	$(CC) $(FLAGS) $(INCLUDE) -c $<  -o $(OBJDIR)$(<:.c=.o)

.PHONY: ${NAME} all compile clean fclean re bonus prep