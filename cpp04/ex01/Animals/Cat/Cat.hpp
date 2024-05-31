#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "../Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public Animal
{
    protected:
        Brain *brain;
    public:
        Cat();
        Cat(std::string type);
        virtual ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif