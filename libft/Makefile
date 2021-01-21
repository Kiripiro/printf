ERASE 	=	\033[2K\r
GREY 	=	\033[30m
RED 	=	\033[31m
GREEN 	=	\033[32m
YELLOW 	=	\033[33m
BLUE 	=	\033[34m
PINK 	=	\033[35m
CYAN 	=	\033[36m
WHITE 	=	\033[37m
END 	=	\033[0m
BOLD 	=	\033[1m
UNDER 	=	\033[4m
SUR 	=	\033[7m

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c  \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

INCS	=	libft.h

OBJS	= 	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

%.o:		%.c $(INCS)
			@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@
			@printf "$(YELLOW)$(ERASE)COMPILING: $(END) $<"

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@printf "$(ERASE)$(GREEN)[LIBFT.A GENERATED] \n$(END)"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
