NAME    =   push_swap

SRCS    =   *.c

HEADER  =   swap.h

GCC             = gcc

RM              = rm -f

CFLAGS	=	-Wall -Werror -Wextra -I ${HEADER}

all:    ${NAME}

${NAME}: ${SRCS}
	${GCC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
		${RM} ${NAME}
fclean:	clean

re:			fclean all
