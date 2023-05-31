#include "Zombie.hpp"
#include <string>

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie();
	zombie->setName(name);
	return zombie;
}
