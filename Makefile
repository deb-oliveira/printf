#OBJS		= 	$(patsubst %.c,%.o,$(wildcard ft*.c))
CC			=	gcc
FILES 		= 	ft_utoa_base.c ft_strrev.c ft_itoa_base.c \
				ft_printf.c ft_putcstr_fd.c ft_uptrtoa_base.c \
				get_specf.c do_specf.c ft_strmjoin.c get_type.c \
				ft_putmem_fd.c ft_memjoin.c ft_max.c ft_strcmp.c \
				ft_u128toa_base.c ft_upointtoa_base.c ft_strcjoin.c \
				ft_strxdup.c ft_strxlen.c ft_min.c ft_bytestoprint.c \
				ft_ftoa_base.c ft_strsublen.c ft_3strjoin.c \
				ft_etoa_base.c ft_strclen.c ft_strclenc.c \
				ft_swap.c ft_gtoa_base.c 
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

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re

