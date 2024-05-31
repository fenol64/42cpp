#include "Cat.hpp"
#include "../Brain/Brain.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "MIAAAAAAAAAAAAAUUUUUUUUUUUUUUU" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}