#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() {}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
