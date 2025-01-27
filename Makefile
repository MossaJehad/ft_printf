SRC = ft_printf.c ft_putchr.c ft_puthex.c ft_putnbr_unsigned.c ft_putnbr.c ft_putpointer.c ft_putstr.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re