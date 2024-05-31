#include <stdio.h>
#include "./Zombie/Zombie.hpp"
#include "./Zombie/zombie_utils.hpp"

int main()
{
	Zombie *zombie1 = newZombie("saiago");
	zombie1->announce();
	delete zombie1;

	Zombie *zombie2 = newZombie("ferd");
	zombie2->announce();
	delete zombie2;

	randomChamp("tegas");
}
