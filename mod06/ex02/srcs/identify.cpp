#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "type: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "type: B\n";
	else
		std::cout << "type: C\n";
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "type: A\n";
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "type: B\n";
		}
		catch (...)
		{
			(void)dynamic_cast<C &>(p);
			std::cout << "type: C\n";
		}
	}
}
