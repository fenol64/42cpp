NAME=claptrap

SRCS=main.cpp ClapTrap/ClapTrap.cpp
OBJS=$(SRCS:.cpp=.o)

COMPILER = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	$(COMPILER) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
