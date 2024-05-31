NAME = phonebook

SRC = main.cpp Contact/Contact.cpp PhoneBook/PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	$(COMPILER) $(FLAGS) -c $< -o $(<:.cpp=.o)


$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME) 

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
