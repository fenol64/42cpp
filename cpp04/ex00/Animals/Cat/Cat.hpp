#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "../Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string type);
        virtual ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        void makeSound() const;
};

#endif