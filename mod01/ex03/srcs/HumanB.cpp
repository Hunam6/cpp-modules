#include "HumanB.hpp"
#include <iostream>

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " attacks with their hand\n";
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}
