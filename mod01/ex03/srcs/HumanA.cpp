#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
