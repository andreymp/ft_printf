NAME = libftprintf.a

SRC = 		ft_printf.c \
			option1.c \
			option2.c \
			utils.c

DOT_H = 	ft_printf.h

MAN =		$(SRC:.c=.o) $(SRC:.c=.d)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

AR =		ar rcs

RM =		rm -rf

$(NAME):	

all:		$(NAME)

clean:		

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
			

.PHONY:		all clean fclean re