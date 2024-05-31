#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal() = 0;
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual std::string getType() const;
        virtual void makeSound() const;
};

#endif