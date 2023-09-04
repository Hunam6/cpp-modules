#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie *zom1 = newZombie("Dym");
	zom1->announce();
	delete zom1;
	randomChump("Static");
}
