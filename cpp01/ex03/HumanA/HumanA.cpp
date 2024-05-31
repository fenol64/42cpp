#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    std::cout << "humano criado" << std::endl;
}

void HumanA::attack() {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
