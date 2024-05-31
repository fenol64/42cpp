#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    std::cout << "humano criado" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack() {
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}