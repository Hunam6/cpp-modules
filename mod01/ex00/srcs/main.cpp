#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie *zom1 = newZombie("Dym");
	zom1->announce();
	randomChump("Static");
	delete zom1;
}
