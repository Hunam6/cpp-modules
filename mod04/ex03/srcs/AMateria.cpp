#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type)
	: type(type) {}

AMateria::AMateria(AMateria &other)
	: type(other.type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria &other)
{
	type = other.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Default AMateria::use member function\n";
}
