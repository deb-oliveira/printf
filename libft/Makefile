#OBJS		= 	$(patsubst %.c,%.o,$(wildcard ft*.c))
CC			=	gcc
FILES 		= 	ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
				ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_iterative_power.c \
				ft_itoa.c ft_signal.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_split.c \
				ft_strmapi.c ft_isspace.c
FILES_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
FILES_EXTRAS = 	ft_utoa_base.c ft_strrev.c ft_itoa_base.c \
				ft_nputcstr_fd.c ft_uptrtoa_base.c ft_strmjoin.c  \
				ft_putmem_fd.c ft_memjoin.c ft_max.c ft_strcmp.c \
				ft_u128toa_base.c ft_upointtoa_base.c ft_strcjoin.c \
				ft_strxdup.c ft_strxlen.c ft_min.c  ft_ftoa.c \
				ft_cstrlen.c ft_str3join.c ft_etoa.c ft_strclen.c \
				ft_strclenc.c ft_swap.c ft_gtoa.c ft_lutoa_base.c \
				ft_llutoa_base.c ft_litoa_base.c ft_llitoa_base.c \
				ft_ftfree.c ft_putcstr_fd.c
OBJS 		=	$(FILES:.c=.o)
OBJS_BONUS 	= $(FILES_BONUS:.c=.o)
OBJS_EXTRAS	= $(FILES_EXTRAS:.c=.o)
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	libft.a
RM 			=	rm -f

###################################################################

all:		$(NAME)

$(NAME):	$(OBJS) bonus extra
				@ar rcs $(NAME) $(OBJS)

%.o:		%.c
				@$(CC) -c $(FLAGS) $<

bonus:		$(OBJS_BONUS)
				@ar rcs $(NAME) $(OBJS_BONUS)

extra:		$(OBJS_EXTRAS)
				@ar rcs $(NAME) $(OBJS_EXTRAS)

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_EXTRAS)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re