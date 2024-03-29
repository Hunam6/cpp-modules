#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " attacks with their hand\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
