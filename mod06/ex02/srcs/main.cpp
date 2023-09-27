#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *random_class = generate();
	Base *classA = new A();
	identify(random_class);
	identify(*random_class);
	identify(classA);
	identify(*classA);
	delete random_class;
	delete classA;
}
