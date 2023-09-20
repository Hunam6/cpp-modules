#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
	: name(name) {}

Zombie::~Zombie()
{
	std::cout << name << " got deleted by life.\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
