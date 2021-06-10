NAME	=	checker

SRCS	=	*.c

HEADER	=	swap.h

LIBM	=   minilibx/libmlx.a

GCC				= gcc

RM				= rm -f

CFLAGS	=	-Wall -Werror -Wextra -I ${HEADER} -framework OpenGL -framework Appkit

all:	${NAME}

${NAME}: ${LIBA} ${LIBM} ${SRCS}
	${GCC} ${CFLAGS} ${SRCS} ${LIBM} -o ${NAME}

${LIBM}:
	make -C minilibx
bonus:  ${NAME}
clean:
	make clean -C ./minilibx
fclean:	clean
		${RM} ${NAME}
re:		fclean all
