cmake_minimum_required(VERSION 3.20)
project(05_1_push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(05_1_push_swap push_swap.c
        src_push_swap/ft_sort1.c src_push_swap/ft_libft.c
        src_push_swap/ft_libft.c libft/ft_arg.c libft/ft_clean.c src_push_swap/ft_stack.c libft/ft_functions1.c libft/ft_functions2.c src_push_swap/ft_commands1.c src_push_swap/ft_sort2.c src_push_swap/ft_commands2.c src_push_swap/ft_commands3.c src_push_swap/ft_commands4.c src_push_swap/ft_sort3.c src_push_swap/ft_sort4.c src_checker/ft_checker.c src_checker/ft_checker.h src_checker/get_next_line.c src_checker/get_next_line.h src_checker/get_next_line_utils.c src_push_swap/ft_parser.c)
