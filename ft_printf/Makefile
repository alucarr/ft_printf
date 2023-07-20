NAME 	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= -rcs
RM		= rm -rf
SRCS 	= ft_printf.c ft_words.c ft_numbers.c
AR		= ar
OBJS	= $(SRCS:.c=.o)

all 	: 	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
