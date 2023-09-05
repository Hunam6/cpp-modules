#pragma once
#ifndef ICE_HPP
#define ICE_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif
