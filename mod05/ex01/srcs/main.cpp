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
	Bureaucrat realJohn("John Smith", 1);
	Bureaucrat fakeJohn("Smith John", 7);

	std::cout << "\nInfo:\n";
	std::cout << form;
	std::cout << realJohn;
	std::cout << fakeJohn;

	std::cout << "\nActions:\n";
	fakeJohn.signForm(form);
	std::cout << form;
	realJohn.signForm(form);
	std::cout << form;
}
