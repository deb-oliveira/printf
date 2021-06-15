#OBJS		= 	$(patsubst %.c,%.o,$(wildcard ft*.c))
CC			=	gcc
FILES 		= 	ft_utoa_base.c ft_strrev.c ft_itoa_base.c \
				ft_printf.c ft_putcstr_fd.c ft_uptrtoa_base.c \
				get_specf.c do_specf.c ft_strmjoin.c get_type.c \
				ft_putmem_fd.c ft_memjoin.c ft_max.c
#FILES_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c 
OBJS 		=	$(FILES:.c=.o)
#OBJS_BONUS 	= $(FILES_BONUS:.c=.o)
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	libftprintf.a
RM 			=	rm -f

###################################################################

all:		$(NAME)

$(NAME):	$(OBJS)
				@make -C libft/
				@ar rc $(NAME) $(OBJS) libft/*.o

%.o:		%.c 
				$(CC) -c $(FLAGS) $<

clean:
				@$(RM) $(OBJS)
				@make clean -C libft/

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re

