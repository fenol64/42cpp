NAME=polymorfism

SRCS=main.cpp \
	Animals/Animal.cpp \
	Animals/Dog/Dog.cpp \
	Animals/Cat/Cat.cpp \
	Animals/WrongAnimal/WrongAnimal.cpp \
	Animals/WrongCat/WrongCat.cpp

OBJS=$(SRCS:.cpp=.o)

COMPILER=g++
FLAGS=-Wall -Wextra -Werror

.cpp.o:
	$(COMPILER) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all