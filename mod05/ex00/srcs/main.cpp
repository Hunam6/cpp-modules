#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bureaucrat("Elie", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	Bureaucrat pep("John Smith", 3);
	pep.demote();
	std::cout << pep;
	pep.promote();
	pep.promote();
	pep.promote();
	std::cout << pep;
	try
	{
		pep.promote();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
