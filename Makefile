NAME = push_swap

# NAME_B = checker_my

HEADER = push_swap.h

# HEADER_B = includes/checker.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ./src_push_swap/ft_commands1.c \
      	./src_push_swap/ft_commands2.c \
      	./src_push_swap/ft_commands3.c \
      	./src_push_swap/ft_commands4.c \
      	./src_push_swap/ft_libft.c \
      	./src_push_swap/ft_sort1.c \
      	./src_push_swap/ft_sort2.c \
      	./src_push_swap/ft_sort_utils1.c \
      	./src_push_swap/ft_stack.c push_swap.c \
      	./libft/ft_arg.c \
        ./libft/ft_clean.c \
        ./libft/ft_functions1.c \
        ./libft/ft_functions2.c

# SRC_B =

OBJ = $(SRC:%.c= %.o)

#OBJ_B = $(SRC_B:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
#	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B) $(HEADER_B)
#	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ_B) -o $(NAME_B)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
#	cd libft && make clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)

fclean	:	clean
#	cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)

re	:	fclean all