#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(AMateria &other)
	: _type(other._type) {}

AMateria::AMateria(std::string const &type)
	: _type(type) {}

AMateria::~AMateria() {}

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
