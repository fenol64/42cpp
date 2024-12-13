NAME=Bureaucrat

SRC=main.cpp Bureaucrat.cpp

OBJ=$(SRC:.cpp=.o)

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all