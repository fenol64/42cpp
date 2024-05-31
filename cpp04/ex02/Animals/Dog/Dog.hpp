#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "../Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string type);
        virtual ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;

};

#endif