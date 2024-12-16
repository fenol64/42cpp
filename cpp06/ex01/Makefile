NAME	=	Serializer

COMPILE	=	c++

FLAG	=	-g -Wall -Wextra -Werror #--std=c++98

SRCS	=	main.cpp Serializer.cpp

all: $(NAME)

$(NAME): ${SRCS}
	${COMPILE} ${FLAG} ${SRCS} -o $(NAME)

clean:
	@rm -rf ${NAME}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all re fclean clean

