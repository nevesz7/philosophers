NAME	= philo

SOURCES	= threats.c \
		check.c \
		errors.c \
		utils.c \
		test.c

HEADERS = philo.h

OBJECTS	= $(SOURCES:.c=.o)

RM		= rm -f

CC 		= cc
PFLAG	= -lpthread
CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJECTS}
		${CC} ${PFLAG} ${CFLAGS} -o ${NAME} ${OBJECTS}

clean:	
		${RM} ${OBJECTS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	re, clean, fclean, all

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}