#pragma once
#ifndef CURE_HPP
#define CURE_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif
