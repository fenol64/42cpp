#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "arma criada" << std::endl;
}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}
