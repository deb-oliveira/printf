#OBJS		= 	$(patsubst %.c,%.o,$(wildcard ft*.c))
CC			=	gcc
FILES 		= 	ft_printf.c get_specf.c do_specf_and_print.c \
				get_type.c ft_bytestoprint.c get_numtype.c do_flags.c \
				ft_printf_fd.c
OBJS 		=	$(FILES:.c=.o)
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	libftprintf.a
RM 			=	rm -f

###################################################################

all:		$(NAME)

$(NAME):	$(OBJS)
				@make -C libft/
				@ar rc $(NAME) $(OBJS) libft/*.o

%.o:		%.c 
				@$(CC) -c $(FLAGS) $<

bonus:		all

clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re

