SRCS = main.cpp Fixed/Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o fixed

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f fixed

re: fclean all

.PHONY: all clean fclean re