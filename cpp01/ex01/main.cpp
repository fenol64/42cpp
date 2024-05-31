#include "./Zombie/Zombie.hpp"
#include "./Zombie/zombie_utils.hpp"

int main()
{
	Zombie	*hord = zombieHorde(10, "fodase");
	zombieHordeAnnounce(10, hord);
	delete[] hord;
}
