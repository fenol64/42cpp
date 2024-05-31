#include <iostream>
#include "ClapTrap/ClapTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"
#include "FragTrap/FragTrap.hpp"

int main ()
{
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3 = claptrap;

    claptrap.attack("enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    ScavTrap scavtrap("Scavtrap");
    ScavTrap scavtrap2(scavtrap);
    ScavTrap scavtrap3 = scavtrap;

    scavtrap.attack("enemy");
    scavtrap.guardGate();

    FragTrap fragtrap("Fragtrap");
    FragTrap fragtrap2(fragtrap);
    FragTrap fragtrap3 = fragtrap;
    fragtrap.attack("enemy");
    fragtrap.highFivesGuys();


    return 0;
}