#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &copy);
        void attack(std::string const & target);
        void guardGate();
};

#endif