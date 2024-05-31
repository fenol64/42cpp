#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal(wrongCat)
{
    *this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    if (this == &wrongCat)
        return *this;
    this->type = wrongCat.type;
    return *this;
}