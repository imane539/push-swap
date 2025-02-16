
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

SRC = mandatory/push_swap.c \
mandatory/utils.c \
mandatory/handler.c \
mandatory/sorting.c \
mandatory/operations.c \
mandatory/stack_operations.c \
mandatory/chunk.c 
LIBFT = libft/libft.a

SRCB = bonus/push_swap_bonus.c \
bonus/utils_bonus.c \
bonus/functions_bonus.c \
bonus/handler_bonus.c \
bonus/operations_bonus.c \
bonus/stack_operations_bonus.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c

OBJECTS =$(SRC:.c=.o)

OBJECTSB =$(SRCB:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all:$(NAME)

$(NAME):$(OBJECTS) $(LIBFT)
	cc	$(CFLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C libft

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJECTSB) $(LIBFT)
	cc	$(CFLAGS) $^ -o $(NAME_BONUS)


clean :
	make fclean -C libft
	rm -f $(OBJECTS) 
	rm -f $(OBJECTSB) 

	
fclean : clean 
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

# .PHONY:re all fclean clean 

.SECONDARY : $(OBJECTS)