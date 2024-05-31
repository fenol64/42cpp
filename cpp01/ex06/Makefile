NAME=harl-filter

SRCS=main.cpp Harl/Harl.cpp
OBJS = $(SRCS:.cpp=.o)

COMPILER = c++
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
