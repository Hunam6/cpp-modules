#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure() {}

	Cure *clone() const;
	void use(ICharacter &target);
};
