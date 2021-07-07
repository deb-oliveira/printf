#OBJS		= 	$(patsubst %.c,%.o,$(wildcard ft*.c))
CC			=	gcc
FILES 		= 	ft_utoa_base.c ft_strrev.c ft_itoa_base.c \
				ft_printf.c ft_nputcstr_fd.c ft_uptrtoa_base.c \
				get_specf.c do_specf_and_print.c ft_strmjoin.c get_type.c \
				ft_putmem_fd.c ft_memjoin.c ft_max.c ft_strcmp.c \
				ft_u128toa_base.c ft_upointtoa_base.c ft_strcjoin.c \
				ft_strxdup.c ft_strxlen.c ft_min.c ft_bytestoprint.c \
				ft_ftoa.c ft_cstrlen.c ft_str3join.c \
				ft_etoa.c ft_strclen.c ft_strclenc.c \
				ft_swap.c ft_gtoa.c ft_lutoa_base.c ft_llutoa_base.c \
				ft_litoa_base.c ft_llitoa_base.c ft_ftfree.c ft_putcstr_fd.c \
				get_numtype.c do_flags.c
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

