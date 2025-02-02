
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c utils.c handler.c
LIBFT = libft/libft.a

OBJECTS =$(SRC:.c=.o)

NAME = push_swap

all:$(NAME)

$(NAME):$(OBJECTS) $(LIBFT)
	cc	$(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft


clean :
	make fclean -C libft
	rm -f $(OBJECTS) 
	
fclean : clean 
	rm -f $(NAME)

re : fclean all

# .PHONY:re all fclean clean 

.SECONDARY : $(OBJECTS)