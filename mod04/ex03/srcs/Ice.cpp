#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	_type = "ice";
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
