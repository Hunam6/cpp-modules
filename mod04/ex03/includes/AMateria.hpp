#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <string>

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(AMateria &other);
	AMateria(std::string const &type);
	virtual ~AMateria();

	AMateria &operator=(AMateria &other);

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
