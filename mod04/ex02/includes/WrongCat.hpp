#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat &other);
	~WrongCat();

	WrongCat &operator=(WrongCat &other);

	void makeSound() const;
};

#endif
