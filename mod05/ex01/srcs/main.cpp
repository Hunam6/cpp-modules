#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form form("TOP SECRET", -1, 4);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	Form form("TOP SECRET", 1, 4);
	Bureaucrat realPep("John Smith", 1);
	Bureaucrat fakePep("Smith John", 7);

	std::cout << form;
	std::cout << realPep;
	std::cout << fakePep;

	fakePep.signForm(form);
	std::cout << form;
	realPep.signForm(form);
	std::cout << form;
}
