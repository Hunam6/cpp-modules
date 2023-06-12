#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice() {}

	Ice *clone() const;
	void use(ICharacter &target);
};
