#include "Dog.hpp"
#include "../Brain/Brain.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
    this->type = copy.type;
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
    return this->brain->getIdea(i);
}