#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
	type = "cure";
}

Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
