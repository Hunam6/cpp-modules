#include "AMateria.hpp"
#include <iostream>

AMateria &AMateria::operator=(AMateria &other)
{
	_type = other._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Default AMateria::use member function\n";
}
