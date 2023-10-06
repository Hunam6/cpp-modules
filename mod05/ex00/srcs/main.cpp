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

	Bureaucrat bureaucrat("John Smith", 3);
	bureaucrat.demote();
	std::cout << bureaucrat;
	bureaucrat.promote();
	bureaucrat.promote();
	bureaucrat.promote();
	std::cout << bureaucrat;
	try
	{
		bureaucrat.promote();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
