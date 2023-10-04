#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(Animal &other);
	virtual ~Animal();

	Animal &operator=(Animal &other);

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
