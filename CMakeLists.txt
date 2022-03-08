cmake_minimum_required(VERSION 3.21)
project(05_1_push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(05_1_push_swap push_swap.c src_push_swap/ft_reverse.c
        src_push_swap/ft_sort.c src_push_swap/ft_libft.c src_push_swap/ft_check_qualities.c
        src_push_swap/ft_libft.c src_push_swap/ft_instructs.c libft/ft_arg.c libft/ft_clean.c)
