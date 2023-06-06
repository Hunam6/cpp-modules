#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
private:
	Brain *brain;

protected:
	std::string type;

	Animal();
	Animal(Animal &other);

public:
	virtual ~Animal();

	Animal &operator=(Animal &other);

	virtual void makeSound() const = 0;
	std::string getType() const;
	Brain *getBrain();
};

#endif
