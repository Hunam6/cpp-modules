#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(Dog &other);
	virtual ~Dog();

	Dog &operator=(Dog &other);

	void makeSound() const;
	Brain *getBrain() const;
};

#endif
