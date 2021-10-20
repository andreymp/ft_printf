NAME = libftprintf.a

SRC = 		ft_printf.c \
			options1.c \
			options2.c \
			utils.c \

DOT_H = 	ft_printf.h

MAN_O =		$(SRC:.c=.o)
MAN_D = 	$(SRC:.c=.d)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -MMD

AR =		ar rcs

RM =		rm -rf

.PHONY:		all clean fclean re

$(NAME):	$(MAN_O)
			make -C libft/
			ar rcs $(NAME) $(MAN_O) libft/*.o

.c.o:
			$(CC) $(CFLAGS) -c $<

all:		$(NAME)
			
clean:		
			$(RM) $(MAN_O) $(MAN_D)
			@make clean -C libft/

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C libft/

re:			fclean all

-include $(MAN_D)