SRCS =	ft_window.c \
		line.c \
		ft_bresenham.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c
       

NAME    = fdf

OBJS    =  $(SRCS:.c=.o)

HEADERS    = includes/

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : library $(NAME)

$(NAME) : library $(OBJS)
	$(CC) $(FLAGS) $(OBJS) Libft/libft.a MacroLibX/libmlx.so PRINTF/libftprintf.a -o $(NAME) -lXext -lX11 -lSDL2

%.o : %.c
	$(CC) $(FLAGS) -ILibft -IMacroLibX/includes -IGNL -IPRINTF -o $@ -c $<  

library :
	make -C Libft
	make -C PRINTF
	make -C MacroLibX

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make -C ./Libft fclean
	make -C ./PRINTF fclean

re : fclean all

.PHONY : all library clean fclean re
