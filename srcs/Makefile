ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m

SRCS	=	srcs/ft_printf.c \
		 	srcs/ft.c \
		 	srcs/parsing.c \
		 	srcs/print_arg.c \
			srcs/digit_treatment.c \
		 	srcs/print_specifier.c \
			srcs/print_c.c \
			srcs/print_d.c \
			srcs/print_p.c \
			srcs/print_s.c \
			srcs/print_u.c \
			srcs/print_x.c \
			srcs/utils_print.c

MAIN	=	main.c

LLDB	=	-g

INCS	= 	incs/ft_printf.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC		=	gcc

RM		=	rm -f

LIBFT	=	libft/libft.a

CFLAGS	=	-Wall -Werror -Wextra

%.o:		%.c $(INCS) $(LIBFT)
			@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@
			@printf "$(YELLOW)$(ERASE)COMPILING: $(END) $<"

$(NAME):	shrek $(OBJS)	
			@cp $(LIBFT) $(NAME)
			@ar rcs $@ $(OBJS)
			@echo "$(UNDER)$(BOLD)$(ERASE)$(GREEN)[$(GREY)L$(RED)I$(GREEN)B$(YELLOW)F$(BLUE)T$(PINK)P$(CYAN)R$(WHITE)I$(GREY)N$(RED)T$(GREEN)F$(YELLOW).$(BLUE)A $(RED)GENERATED]$(END)"

$(LIBFT):	
			@make -C libft

all:		$(NAME)

clean:		
			@make clean -C libft/ 
			@$(RM) $(OBJS)	
			@echo "\x1b[32m[CLEAN DONE]\x1b[37m"

gcc_not_flag:	re
				@clear && $(CC) $(MAIN) $(NAME) && ./a.out && rm a.out
				@make clean -C libft/
				@$(RM) $(OBJS)

gcc_lldb_not_flag:	re
					@clear && $(CC) $(LLDB) $(MAIN) $(NAME) && lldb a.out
					@make clean -C libft/
					@$(RM) $(OBJS)

gcc_lldb:	re
			@clear && $(CC) $(CFLAGS) $(LLDB) $(MAIN) $(NAME) && lldb a.out
			@make clean -C libft/
			@$(RM) $(OBJS)


gcc:		re
			@clear && $(CC) $(CFLAGS) $(MAIN) $(NAME) && ./a.out && rm a.out
			@make clean -C libft/
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean -C libft/
			@$(RM) $(NAME)
			@echo "\x1b[32m[FCLEAN DONE]\x1b[37m"

ART:
			@for i in {232..255} ; \
			do                                      \
				sleep 0.1;\
				clear;\
				for y in {22..27} {27..22};             \
				do \
					printf "\033[48;5;$${y}m      \033[0m" ;\
				done ; echo ;                              \
				echo "     \033[38;5;$${i}m_____ _____ _   _ _____ ___  _____ _   _  ___________  _____\033[0m";\
				echo "    \033[38;5;$${i}m/  __ \  _  | \ | |_   _/ _ \|_   _| \ | ||  ___| ___ \/  ___|\033[0m";\
				echo "    \033[38;5;$${i}m| /  \/ | | |  \| | | |/ /_\ \ | | |  \| || |__ | |_/ /\  --. \033[0m";\
				echo "    \033[38;5;$${i}m| |   | | | | . ' | | ||  _  | | | | . ' ||  __||    /  '--. \ \033[0m";\
				echo "    \033[38;5;$${i}m| \__/\ \_/ / |\  | | || | | |_| |_| |\  || |___| |\ \ /\__/ /\033[0m";\
				echo "     \033[38;5;$${i}m\____/\___/\_| \_/ \_/\_| |_/\___/\_| \_/\____/\_| \_|\____/\033[0m";\
				for y in {22..27} {27..22};             \
				do                                  \
					printf "\033[48;5;$${y}m      \033[0m" ;\
				done ; echo ;                              \
			done

re:			fclean all

shrek:		
	@printf "$(GREEN)\n⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ 	      ::::::::::   :::::::::::                       :::::::::       :::::::::       :::::::::::       ::::    :::   :::::::::::       :::::::::: \n⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿ 	     :+:              :+:                           :+:    :+:      :+:    :+:          :+:           :+:+:   :+:       :+:           :+:    \n⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀ 	    +:+              +:+                           +:+    +:+      +:+    +:+          +:+           :+:+:+  +:+       +:+           +:+          \n⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 	   :#::+::#         +#+                           +#++:++#+       +#++:++#:           +#+           +#+ +:+ +#+       +#+           :#::+::#      \n⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 	  +#+              +#+                           +#+             +#+    +#+          +#+           +#+  +#+#+#       +#+           +#+            \n⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ 	 #+#              #+#                           #+#             #+#    #+#          #+#           #+#   #+#+#       #+#           #+#             \n⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ 	###              ###           ##########      ###             ###    ###      ###########       ###    ####       ###           ###              \n⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉			               $(END)\n\n"

.PHONY:		all clean fclean re gcc shrek
