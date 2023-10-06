#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;

	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;

	AForm *ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "John");
	std::cout << *ppf;

	AForm *scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Maria");
	std::cout << *scf;

	AForm *wtf;
	wtf = someRandomIntern.makeForm("shrubbery creation_", "Jeff");
	std::cout << wtf << "(should be zero)\n";
}
