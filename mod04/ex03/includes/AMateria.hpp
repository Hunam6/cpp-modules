#pragma once
#include "ICharacter.hpp"
#include <string>

class AMateria
{
protected:
	std::string _type;

public:
	AMateria() {}
	AMateria(AMateria &other) : _type(other._type) {}
	AMateria(std::string const &type) : _type(type) {}
	virtual ~AMateria() {}

	AMateria &operator=(AMateria &other);

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};
