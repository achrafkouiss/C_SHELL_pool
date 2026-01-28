NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
CFILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OFILES = $(CFILES:.c=.o)

all : $(NAME)

${NAME} : ${OFILES}
	${AR} ${ARFLAGS} $@ $^

%.o: %.c
	${CC} ${CFLAGS} -Iincludes -c $< -o $@ 

clean :
	rm -f ${OFILES}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all fclean clean re
