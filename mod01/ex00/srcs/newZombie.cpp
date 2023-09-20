#include "Zombie.hpp"
#include <string>

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}
