GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	push_swap

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	swap_functions.c rotate_functions.c reverserotate_functions.c push_functions.c doublylinklist_utils.c doublylinklist_utils2.c doublylinklist_utils3.c sort_3.c sort_5.c push_swap.c sort_large.c sort_large_utils.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	#-Wall -Wextra -Werror 

.c.o:			
				$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Push_swap is ready to sort! Please give some random integers as input..$(RESET)"

all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(OBJS)
re: fclean all
.PHONY: all clean fclean re bonus