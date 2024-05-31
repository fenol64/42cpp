#include <iostream>
#include "./Zombie.hpp"
#include "./zombie_utils.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string zname) : name(zname) {}
Zombie::~Zombie(){
	std::cout << this->getName() << " destroyed" << std::endl;
};

void Zombie::announce()
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

void Zombie::setName(std::string name)
{
	this->name = name;
};


std::string Zombie::getName()
{
	return this->name;
};

Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}

void randomChamp(std::string name)
{
	Zombie mzombie = Zombie(name);
	mzombie.announce();
}



