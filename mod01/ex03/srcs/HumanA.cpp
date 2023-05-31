#include "HumanA.hpp"
#include <iostream>

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
