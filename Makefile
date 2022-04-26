##
## Makefile for my_stdlib in /home/duhame_t
## 
## Made by tanguy duhamel
## Login   <duhame_t@epitech.net>
## 
## Started on  Mon Mar 21 14:34:02 2016 tanguy duhamel
## Last update Tue Apr 12 21:32:33 2016 tanguy duhamel
##

NAME		=	mysh

LIB_NAME	=	libmystd.a

CC		=	gcc

LIB_SRCS	=	lib/srcs/string/my_strlen.c				\
			lib/srcs/string/my_strdup.c				\
			lib/srcs/string/my_strcpy.c				\
			lib/srcs/string/my_strncpy.c				\
			lib/srcs/string/my_strcat.c				\
			lib/srcs/string/my_strcasecmp.c				\
			lib/srcs/string/my_strncasecmp.c			\
			lib/srcs/string/my_memcpy.c				\
			lib/srcs/string/my_memset.c				\
			lib/srcs/string/my_strchr.c				\
			lib/srcs/string/my_strrchr.c				\
			lib/srcs/string/my_strrev.c				\
			lib/srcs/string/my_strcmp.c				\
			lib/srcs/string/my_strstr.c				\
			lib/srcs/io/my_putchar.c				\
			lib/srcs/io/my_puts.c					\
			lib/srcs/io/my_fgets.c					\
			lib/srcs/io/my_fopen.c					\
			lib/srcs/io/my_fread.c					\
			lib/srcs/io/my_fwrite.c					\
			lib/srcs/io/my_printf.c					\
			lib/srcs/io/my_fprintf.c				\
			lib/srcs/io/my_dprintf.c				\
			lib/srcs/io/my_vprintf.c				\
			lib/srcs/io/my_vfprintf.c				\
			lib/srcs/io/my_vdprintf.c				\
			lib/srcs/io/my_scanf.c					\
			lib/srcs/malloc/my_realloc.c				\
			lib/srcs/ctype/my_isdigit.c				\
			lib/srcs/ctype/my_isalpha.c				\
			lib/srcs/ctype/my_isalnum.c				\
			lib/srcs/ctype/my_isblank.c				\
			lib/srcs/ctype/my_isspace.c				\
			lib/srcs/ctype/my_isupper.c				\
			lib/srcs/ctype/my_islower.c				\
			lib/srcs/stdlib/my_itoa.c				\
			lib/srcs/stdlib/my_atoi.c				\
			lib/srcs/stdlib/my_strtol.c				\
			lib/srcs/math/my_pow.c					\
			lib/srcs/customs/utils/my_str_realcat.c			\
			lib/srcs/customs/utils/my_split.c			\
			lib/srcs/customs/utils/free_dtab.c			\
			lib/srcs/customs/utils/my_fdputchar.c			\
			lib/srcs/customs/utils/my_fdputnbr.c			\
			lib/srcs/customs/utils/my_fdputfloat.c			\
			lib/srcs/customs/utils/variable_utils.c			\
			lib/srcs/customs/utils/linked_list.c			\
			lib/srcs/customs/utils/my_len.c				\
			lib/srcs/customs/utils/my_str_utils.c			\
			lib/srcs/customs/utils/my_convert_base.c		\
			lib/srcs/customs/utils/printf_utils.c			\
			lib/srcs/customs/utils/printf_advanced_utils.c		\
			lib/srcs/customs/io/get_next_line.c

SRCS		=	srcs/main.c						\
			srcs/env_utils.c					\
			srcs/shell_utils.c					\
			srcs/free_utils.c					\
			srcs/command_parser.c					\
			srcs/command_lexer.c					\
			srcs/command_exec.c					\
			srcs/command_utils.c					\
			srcs/exec_utils.c					\
			srcs/simple_command_utils.c				\
			srcs/tab_utils.c					\
			srcs/my_pwd.c						\
			srcs/buildins_utils.c					\
			srcs/exit_utils.c					\
			srcs/my_cd.c						\
			srcs/env_utils_buildins.c				\
			srcs/my_str_utils.c					\
			srcs/pipe_utils.c					\
			srcs/setenv_utils.c					\
			srcs/my_unsetenv.c					\
			srcs/redirection_utils.c				\
			srcs/open_redirection_utils.c				\
			srcs/left_redirection_utils.c

CFLAGS		+=	-W -Wall -Wextra -Iinclude

OBJS		=	$(SRCS:.c=.o)

LIB_OBJS	=	$(LIB_SRCS:.c=.o)

all:			$(LIB_NAME) $(NAME)

$(LIB_NAME):		$(LIB_OBJS)
			ar rc $(LIB_NAME) $(LIB_OBJS)
			ranlib $(LIB_NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) -L. -lmystd

clean:
			rm -f $(OBJS)
			rm -f $(LIB_OBJS)

fclean:			clean
			rm -f $(NAME)
			rm -f $(LIB_NAME)

re:			fclean all
