#include <iostream>

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this == &brain)
        return *this;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

void Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}
