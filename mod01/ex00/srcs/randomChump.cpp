#include "Zombie.hpp"
#include <string>

void randomChump(std::string name)
{
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}
