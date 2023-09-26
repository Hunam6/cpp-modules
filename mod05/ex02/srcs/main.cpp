#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{

	ShrubberyCreationForm shrubbery_form;
	RobotomyRequestForm robotomy_form("Harl");
	PresidentialPardonForm pardon_form;
	Bureaucrat realPep("John Smith", 1);
	Bureaucrat fakePep("Smith John", 150);

	realPep.signForm(shrubbery_form);
	realPep.signForm(robotomy_form);
	realPep.signForm(pardon_form);

	fakePep.executeForm(shrubbery_form); // shouldn't work
	realPep.executeForm(shrubbery_form);
	realPep.executeForm(robotomy_form);
	realPep.executeForm(pardon_form);
}
