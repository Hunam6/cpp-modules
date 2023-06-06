#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat &other);
	~Cat();

	Cat &operator=(Cat &other);

	void makeSound() const;
};

#endif
